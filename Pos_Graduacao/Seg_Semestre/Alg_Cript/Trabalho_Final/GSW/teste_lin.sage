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
    return Zx(bits)   # Zx já cria o polinômio com coeficientes adequados
# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
# Controle da escrita dos testes de ruido para valores de L muito grandes
def deve_logar(i, n):
    if n <= 8:
        return True
    elif n <= 256:
        return (i % 16 == 0) or (i == n - 1)
    elif n <= 4096:
        return (i % 64 == 0) or (i == n - 1)
    else:
        return (i % 8192 == 0) or (i == n - 1)
# -----------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------
# Método para executar os testes
def executar_teste(l, M, gsw, ruido_writer, teste_id):
    proc = psutil.Process(os.getpid())
    n = M.shape[0]

    # ------------------------------------------------------------------------------
    # Estágio 2 - Pré-processamento: Preparação dos ambientes
    t2_start = time.time()

    ele_des1 = rd.randint(0, n - 1)

    # vetor one-hot
    cipher_m_1 = []
    for i in range(n):
        c = gsw.enc(1 if i == ele_des1 else 0)
        cipher_m_1.append(c)

        if deve_logar(i, n):
            noise = gsw.get_noise(c, 1 if i == ele_des1 else 0)
            ruido_writer.writerow([
                teste_id, "enc_onehot", i,
                noise, time.time() - t2_start, f"onehot={i}"
            ])

    # cifrar matriz M
    cipher_M = []
    for i in range(n):                      # Polinomialização e criptografação
        bits = int_to_bits(int(M[i]), l)
        poly = bits_to_poly(bits)
        c = gsw.enc(poly)
        cipher_M.append(c)

        if deve_logar(i, n):
            noise = gsw.get_noise(c, poly)
            ruido_writer.writerow([
                teste_id, "enc_db", i,
                noise, time.time() - t2_start, f"M={int(M[i])}"
            ])

    t2_end = time.time()
    ram_after_preproc = round(proc.memory_info().rss / (1024**2))

    # ------------------------------------------------------------------------------
    # Estágio 3 - Recuperação dos elementos

    t3_start = time.time()

    res = gsw.mult(cipher_m_1[0], cipher_M[0])

    if deve_logar(0, n):
        noise = gsw.get_noise(res, bits_to_poly(int_to_bits(int(M[0]), l)) if ele_des1 == 0 else Zx([0]))
        ruido_writer.writerow([
            teste_id, "mult", 0,
            noise, time.time() - t3_start, "i=0"
        ])

    # Seleção do elemento através do produto vetorial
    for i in range(1, n):
        term = gsw.mult(cipher_m_1[i], cipher_M[i])
        res = gsw.add(res, term)

        if deve_logar(i, n):
            expected = bits_to_poly(int_to_bits(int(M[i]), l)) if i == ele_des1 else Zx([0])
            noise = gsw.get_noise(res, expected)
            ruido_writer.writerow([
                teste_id, "accum", i,
                noise, time.time() - t3_start, f"i={i}"
            ])

    t3_end = time.time()

    # ------------------------------------------------------------------------------
    # Verificação + medição final de ruído e RAM

    dec_poly = gsw.dec(res)
    bits = dec_poly.list()
    dec = sum(bits[i] << i for i in range(len(bits)))

    assert dec == M[ele_des1]

    expected_final = bits_to_poly(int_to_bits(int(M[ele_des1]), l))
    final_noise = gsw.get_noise(res, expected_final)

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
# Função de testes
def testar(nome_csv, l, M):
    N_TESTES = 10                                       # Número de testes
    proc = psutil.Process(os.getpid())

    nome_ruido = nome_csv.replace(".csv", "_ruido.csv")
    ruido_f = open(nome_ruido, "w", newline="")
    ruido_writer = csv.writer(ruido_f)

    ruido_writer.writerow([
        "Teste", "Operacao", "Indice",
        "Noise_log2", "Time", "Obs"
    ])

    print("\n=====================================")
    print("Teste de", 2**l, "elementos")
    print("=====================================")

    arquivo_existe = os.path.isfile(nome_csv)
    with open(nome_csv, "a", newline="") as f:
        writer = csv.writer(f)

        if not arquivo_existe:
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
            gsw = GSW(n=832, q=2^30, sigma=3.2, B=2^3)
            t1_end = time.time()

            ram_after_stage1 = round(proc.memory_info().rss / (1024**2))

            metrics = executar_teste(l, M, gsw, ruido_writer, t)

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
# Descomente quando quiser executar. Cuidado com M20 - Dezenas de GB de RAM necessários

#M2  = np.array([0, 1, 2, 3])
#M8  = np.arange(256)
M10 = np.arange(1024)
#M20 = np.arange(1048576)

#testar("resultados_linear_4.csv",        2,  M2)   # parâmetros recomendados: n=512, q=2^15, sigma=3.2, B=2
#testar("resultados_linear_256.csv",      8,  M8)   # parâmetros recomendados: n=832, q=2^30, sigma=3.2, B=2^3
#testar("resultados_linear_1024.csv",    10, M10)   # parâmetros recomendados: n=832, q=2^30, sigma=3.2, B=2^3
#testar("resultados_linear_1048576.csv", 20, M20)
