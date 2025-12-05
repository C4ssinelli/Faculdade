import numpy as np
import random as rd
import time
import csv
import psutil
import os
from statistics import mean, mode, StatisticsError
load("GSW.sage")

# -----------------------------------------------------------------------------------------------
# Funções para representação em bits e polinomialização
def int_to_bits(x, k):
    return [(x >> i) & 1 for i in range(k)]

def bits_to_poly(bits):
    return Zx(bits)
# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
# Controle da escrita dos testes de ruido para valores de L muito grandes
def deve_logar(i, n):
    if n <= 8:
        return True
    elif n <= 256:
        return (i % 16 == 0) or (i == n - 1)
    elif n <= 1024:
        return (i % 64 == 0) or (i == n - 1)
    else:
        return (i % 2^15 == 0) or (i == n - 1)
# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
# Método para executar os testes
def executar_teste(l, M, gsw, ruido_writer, teste_id):
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
        msg = 1 if i == ele_des1 else 0
        c = gsw.enc(msg)
        cipher_m_1.append(c)

        if deve_logar(i, n):
            noise = gsw.get_noise(c, Zx([msg]))
            ruido_writer.writerow([
                teste_id, "enc_onehot_row", i,
                noise, time.time() - t2_start, f"i={i}"
            ])

    # vetor one-hot 2
    for j in range(m):
        msg = 1 if j == ele_des2 else 0
        c = gsw.enc(msg)
        cipher_m_2.append(c)

        if deve_logar(j, m):
            noise = gsw.get_noise(c, Zx([msg]))
            ruido_writer.writerow([
                teste_id, "enc_onehot_col", j,
                noise, time.time() - t2_start, f"j={j}"
            ])

    # cifrar matriz M
    cipher_M = []
    for i in range(n):
        row = []
        for j in range(m):                          # Polinomialização e criptografação
            bits = int_to_bits(int(M[i][j]), l)
            poly = bits_to_poly(bits)
            c = gsw.enc(poly)
            row.append(c)

            if deve_logar(j, m):
                noise = gsw.get_noise(c, poly)
                ruido_writer.writerow([
                    teste_id, "enc_matrix", f"{i},{j}",
                    noise, time.time() - t2_start, f"M={int(M[i][j])}"
                ])
        cipher_M.append(row)

    t2_end = time.time()
    ram_after_preproc = round(proc.memory_info().rss / (1024**2))

    # ------------------------------------------------------------------------------
    # Estágio 3 - Recuperação dos elementos
    t3_start = time.time()

    temp = []

    # Seleção da linha com o elemento desejado com produto matricial (cipher_1 * M)
    for j in range(m):

        acc = gsw.mult(cipher_m_1[0], cipher_M[0][j])

        if deve_logar(j, m):
            expected = bits_to_poly(int_to_bits(int(M[0][j]), l)) if ele_des1 == 0 else Zx([0])
            noise = gsw.get_noise(acc, expected)
            ruido_writer.writerow([
                teste_id, "mult_row", f"0,{j}",
                noise, time.time() - t3_start, f"j={j}"
            ])

        for i in range(1, n):
            term = gsw.mult(cipher_m_1[i], cipher_M[i][j])
            acc = gsw.add(acc, term)

            if deve_logar(i, n):
                expected = bits_to_poly(int_to_bits(int(M[i][j]), l)) if i == ele_des1 else Zx([0])
                noise = gsw.get_noise(acc, expected)
                ruido_writer.writerow([
                    teste_id, "accum_row", f"{i},{j}",
                    noise, time.time() - t3_start, f"i={i},j={j}"
                ])

        temp.append(acc)

    temp = np.array(temp, dtype=object)

    # Seleção do elemento desejado com produto vetorial (M * cipher_2)
    res = gsw.mult(temp[0], cipher_m_2[0])

    if deve_logar(0, m):
        expected = bits_to_poly(int_to_bits(int(M[ele_des1][0]), l)) if ele_des2 == 0 else Zx([0])
        noise = gsw.get_noise(res, expected)
        ruido_writer.writerow([
            teste_id, "mult_col", 0,
            noise, time.time() - t3_start, "j=0"
        ])

    for j in range(1, m):
        term = gsw.mult(temp[j], cipher_m_2[j])
        res = gsw.add(res, term)

        if deve_logar(j, m):
            expected = bits_to_poly(int_to_bits(int(M[ele_des1][j]), l)) if j == ele_des2 else Zx([0])
            noise = gsw.get_noise(res, expected)
            ruido_writer.writerow([
                teste_id, "accum_col", j,
                noise, time.time() - t3_start, f"j={j}"
            ])

    t3_end = time.time()


    # ------------------------------------------------------------------------------
    # Verificação + medição final de ruído e RAM
    dec_poly = gsw.dec(res)
    bits = dec_poly.list()
    dec = sum(bits[i] << i for i in range(len(bits)))

    valor_original = M[ele_des1][ele_des2]
    assert dec == valor_original

    final_expected_poly = bits_to_poly(int_to_bits(valor_original, l))
    final_noise = gsw.get_noise(res, final_expected_poly)

    ruido_writer.writerow([
        teste_id, "final", -1,
        final_noise, time.time() - t3_start, "final"
    ])

    ram_after_ops = round(proc.memory_info().rss / (1024**2))

    return {
        "resultado": dec,
        "t_preproc": t2_end - t2_start,
        "t_ops": t3_end - t3_start,
        "ram_preproc": ram_after_preproc,
        "ram_ops": ram_after_ops
    }
# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
# Função Principal de Testes
def testar(nome_csv, l, M):
    N_TESTES = 10                                   # Número de testes

    print("\n=====================================")
    print("Teste de", 2**l, "elementos")
    print("=======================================")

    proc = psutil.Process(os.getpid())

    nome_ruido = nome_csv.replace(".csv", "_ruido.csv")
    arquivo_existe = os.path.isfile(nome_csv)

    ruido_f = open(nome_ruido, "a", newline="")
    ruido_writer = csv.writer(ruido_f)

    if not os.path.isfile(nome_ruido):
        ruido_writer.writerow(["Teste", "Operacao", "Indice", "Noise_log2", "Time", "Obs"])

    with open(nome_csv, "a", newline="") as f:
        writer = csv.writer(f)

        if not arquivo_existe:
            writer.writerow([
                "Teste", "Total_time", "Stage1_instantiation",
                "Stage2_preprocessing", "Stage3_operations",
                "RAM_after_stage1", "RAM_after_stage2",
                "RAM_after_stage3", "Resultado"
            ])

        for t in range(1, N_TESTES + 1):
            print(f"Iniciando teste #{t}")

            t0 = time.time()

            # ------------------------------------------------------------------------------
            # Estágio 1 - Instanciação do esquema

            t1_start = time.time()
            gsw = GSW(n=512, q=2^15, sigma=3.2, B=2)
            t1_end = time.time()

            ram_after_stage1 = round(proc.memory_info().rss / (1024**2))

            metrics = executar_teste(l, M, gsw, ruido_writer, t)

            t_end = time.time()

            writer.writerow([
                t, t_end - t0, t1_end - t1_start,
                metrics["t_preproc"], metrics["t_ops"],
                ram_after_stage1, metrics["ram_preproc"],
                metrics["ram_ops"], metrics["resultado"]
            ])

    ruido_f.close()
# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
# Chamada para execução dos testes. 
# Descomente quando quiser executar. Cuidado com M20 - Dezenas de GB de RAM necessários
# parâmetros recomendados: n=512, q=2^15, sigma=3.2, B=2

#M2 = np.arange(4).reshape(2,2)
#M8  = np.arange(256).reshape(16,16)
#M10 = np.arange(1024).reshape(32,32)
#M20 = np.arange(10486=576).reshape(1024,1024)

#testar("resultados_matriz_4.csv",         2,  M2)
#testar("resultados_matriz_256.csv",       8,  M8)
#testar("resultados_matriz_1024.csv",     10, M10)
#testar("resultados_matriz_1048579.csv",     20, M20)
