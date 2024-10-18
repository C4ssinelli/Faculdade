# Este código criptografa o texto do arquivo presa.txt

import os
import time
import Pre_Cod
import Cod

files = []
for file in os.listdir():
    if file == "presa.txt":
        files.append(file)

print("Arquivos travados: ", files)

n, p, q = Pre_Cod.Calcula_n()
with open("chave.txt", "wt") as chaves:
    chaves.write(str(p))
    chaves.write(" ")
    chaves.write(str(q))

t_ini_1 = time.time()

for file in files:
    with open(file, "rt") as thefile:
        conteudo = thefile.read()
    conteudo_travado = Cod.Transformar(conteudo, n)
    with open(file, "wt") as thefile:
        thefile.write(str(conteudo_travado))

t_fin_1 = time.time()

print("A presa foi pega")
print("levou", t_fin_1 - t_ini_1, "segundos")
