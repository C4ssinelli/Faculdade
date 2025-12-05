import numpy as np
import random as rd
import time
import csv
import psutil
import os
from statistics import mean, mode, StatisticsError
load("dghv.sage")

security = 128              # bits de segurança

# -----------------------------------------------------------------------------------------------
# Controle da escrita dos testes de ruido para valores de L muito grandes
def deve_logar(i, n):
    if n <= 8:
        return True
    elif n <= 256:
        return (i % 16 == 0) or (i == n-1)
    elif n <= 4096:
        return (i % 64 == 0) or (i == n-1)
    else:
        return (i % 32768 == 0) or (i == n-1)
# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
def executar_teste(l, M, dghv, ruido_writer, teste_id):
    proc = psutil.Process(os.getpid())

    n = M.shape[0]
    m = M.shape[1]

    # ------------------------------------------------------------------------------
    # Estágio 2 - Pré-processamento: Preparação dos ambientes

    t2_start = time.time()

    ele_des1 = rd.randint(0, n - 1)
    ele_des2 = rd.randint(0, m - 1)

    cipher_m_1 = []
    cipher_m_2 = []

    # vetor one-hot 1
    for i in range(n):
        c = dghv.enc(1 if i == ele_des1 else 0)
        cipher_m_1.append(c)

        if deve_logar(i, n):
            noise = get_noise_dghv(dghv, c, 1 if i == ele_des1 else 0)
            ruido_writer.writerow([
                teste_id, "enc_onehot_1", i,
                noise, ruido_norm(noise, dghv.p),
                time.time() - t2_start,
                f"i={i},hot={i==ele_des1}"
            ])

    # vetor one-hot 2
    for j in range(m):
        c = dghv.enc(1 if j == ele_des2 else 0)
        cipher_m_2.append(c)

        if deve_logar(j, m):
            noise = get_noise_dghv(dghv, c, 1 if j == ele_des2 else 0)
            ruido_writer.writerow([
                teste_id, "enc_onehot_2", j,
                noise, ruido_norm(noise, dghv.p),
                time.time() - t2_start,
                f"j={j},hot={j==ele_des2}"
            ])

    # cifrar matriz M
    cipher_M = []
    for i in range(n):
        row = []
        for j in range(m):
            c = dghv.enc(int(M[i][j]))
            row.append(c)

            if deve_logar(j, m):
                noise = get_noise_dghv(dghv, c, int(M[i][j]))
                ruido_writer.writerow([
                    teste_id, "enc_db", f"{i},{j}",
                    noise, ruido_norm(noise, dghv.p),
                    time.time() - t2_start,
                    f"M[{i}][{j}]={M[i][j]}"
                ])
        cipher_M.append(row)

    t2_end = time.time()
    ram_after_preproc = round(proc.memory_info().rss / 1024**2)

    # ------------------------------------------------------------------------------
    # Estágio 3 - Recuperação dos elementos

    t3_start = time.time()

    temp = []

    # Seleção da linha com o elemento desejado com produto matricial (cipher_1 * M)
    for j in range(m):

        acc = dghv.mult(cipher_m_1[0], cipher_M[0][j])

        if deve_logar(0, n):
            expected = M[0][j] if ele_des1 == 0 else 0
            noise = get_noise_dghv(dghv, acc, expected)
            ruido_writer.writerow([
                teste_id, "mult_row", f"0,{j}",
                noise, ruido_norm(noise, dghv.p),
                time.time() - t3_start,
                f"row mult j={j}"
            ])

        for i in range(1, n):
            term = dghv.mult(cipher_m_1[i], cipher_M[i][j])
            acc = dghv.add(acc, term)

            if deve_logar(i, n):
                expected = M[i][j] if i == ele_des1 else 0
                noise = get_noise_dghv(dghv, acc, expected)
                ruido_writer.writerow([
                    teste_id, "accum_row", f"{i},{j}",
                    noise, ruido_norm(noise, dghv.p),
                    time.time() - t3_start,
                    f"acc row j={j}"
                ])

        temp.append(acc)

    temp = np.array(temp, dtype=object)

    # Seleção do elemento desejado com produto vetorial (M * cipher_2)
    res = dghv.mult(temp[0], cipher_m_2[0])

    if deve_logar(0, m):
        expected = M[ele_des1][0] if ele_des2 == 0 else 0
        noise = get_noise_dghv(dghv, res, expected)
        ruido_writer.writerow([
            teste_id, "mult_col", "0",
            noise, ruido_norm(noise, dghv.p),
            time.time() - t3_start,
            "col mult"
        ])

    for j in range(1, m):
        term = dghv.mult(temp[j], cipher_m_2[j])
        res = dghv.add(res, term)

        if deve_logar(j, m):
            expected = M[ele_des1][j] if j == ele_des2 else 0
            noise = get_noise_dghv(dghv, res, expected)
            ruido_writer.writerow([
                teste_id, "accum_col", j,
                noise, ruido_norm(noise, dghv.p),
                time.time() - t3_start,
                "col accum"
            ])

    t3_end = time.time()

    # ------------------------------------------------------------------------------
    # Verificação + medição final de ruído e RAM

    dec = dghv.dec(res)
    #print("elemento decifrado =", dec)
    assert dec == M[ele_des1][ele_des2]

    final_noise = get_noise_dghv(dghv, res, int(M[ele_des1][ele_des2]))
    ruido_writer.writerow([
        teste_id, "final", -1,
        final_noise, ruido_norm(final_noise, dghv.p),
        time.time() - t3_start,
        "final_value"
    ])

    ram_after_ops = round(proc.memory_info().rss / 1024**2)

    return {
        "resultado": dec,
        "t_preproc": t2_end - t2_start,
        "t_ops": t3_end - t3_start,
        "ram_preproc": ram_after_preproc,
        "ram_ops": ram_after_ops
    }


# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
# Função de testes
def testar(nome_csv, l, M):
    N_TESTES = 10                                       # Número de testes
    proc = psutil.Process(os.getpid())

    nome_ruido = nome_csv.replace(".csv", "_ruido.csv")
    ruido_f = open(nome_ruido, "w", newline="")
    ruido_writer = csv.writer(ruido_f)

    ruido_writer.writerow([
        "Teste", "Operacao", "Indice",
        "Noise_abs", "Noise_norm", "Time", "Obs"
    ])

    print("\n=====================================")
    print("Teste de", 2**l, "elementos")
    print("=======================================")

    with open(nome_csv, "w", newline="") as f:
        writer = csv.writer(f)

        writer.writerow([
            "Teste",
            "Total_time",
            "Stage1_instantiation",
            "Stage2_preprocessing",
            "Stage3_operations",
            "RAM_after_stage1",
            "RAM_after_stage2",
            "RAM_after_stage3",
            "Resultado"
        ])

        for t in range(1, N_TESTES + 1):
            print(f"Iniciando teste #{t}")

            t0 = time.time()

            # ------------------------------------------------------------------------------
            # Estágio 1 - Instanciação do esquema

            t1_start = time.time()

            dghv = DGHV(security**2, (l+5)*security, security)

            t1_end = time.time()
            ram_after_stage1 = round(proc.memory_info().rss / 1024**2)

            metrics = executar_teste(l, M, dghv, ruido_writer, t)

            t_end = time.time()

            writer.writerow([
                t,
                t_end - t0,
                t1_end - t1_start,
                metrics["t_preproc"],
                metrics["t_ops"],
                ram_after_stage1,
                metrics["ram_preproc"],
                metrics["ram_ops"],
                metrics["resultado"]
            ])

    ruido_f.close()
# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
# Chamada para execução dos testes. 
# Descomente quando quiser executar. Cuidado com M20 - costuma demorar

#M2  = np.arange(4).reshape(2,2)
#M8  = np.arange(256).reshape(16,16)
#M10 = np.arange(1024).reshape(32,32)
#M20 = np.arange(1048576).reshape(1024,1024)

#testar("resultados_matriz_4.csv",        2,  M2)
#testar("resultados_matriz_256.csv",      8,  M8)
#testar("resultados_matriz_1024.csv",    10, M10)
#testar("resultados_matriz_1048576.csv", 20, M20)
