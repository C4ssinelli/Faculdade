# Este código descriptografa o arquivo presa.txt, dependendo do input de uma senha
import os
import time
import Decod

def Convert(string):
    li = list(string.split(" "))
    return li

files = []
for file in os.listdir():
    if file == "presa.txt":
        files.append(file)

with open("chave.txt", "rt") as chave:
    chave_secreta = chave.read()

lista_secreta = Convert(chave_secreta)
p = int(lista_secreta[0])
q = int(lista_secreta[1])

senha = "presa"

escreva_me = input("Diga a senha: ")

if escreva_me == senha:
    t_ini_1 = time.time()
    for file in files:
        with open(file, "rt") as arq:
            conteudo = arq.read()
            lista_conteudo = Convert(conteudo)
            lista_final = []
            for i in range(len(lista_conteudo)):
                if lista_conteudo[i] != " ":
                    lista_final.append(int(lista_conteudo[i]))

            conteudo_temporario = Decod.Decodifica(lista_final, p, q)
            conteudo_final = Decod.Troca_Numeros(conteudo_temporario)
            
        with open(file, "wt") as arq:
            arq.write(conteudo_final)
        t_fin_1 = time.time()
        print("Obrigado pela doação!")
        print("Levou", t_fin_1 - t_ini_1, "segundos")
else:
    print("Tente de novo")
