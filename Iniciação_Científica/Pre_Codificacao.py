# Este código serve de base para a Pré-Codificação
import random
import datetime

# Este método converte as palavras em números
def Conversao(Frase):
    Convertido = ""
    Frase = Frase.upper()
    Tamanho = len(Frase)
    for i in range(Tamanho):
        if Frase[i] == "A":
            Convertido = Convertido + "11"
        if Frase[i] == "B":
            Convertido = Convertido + "12"
        if Frase[i] == "C":
            Convertido = Convertido + "13"
        if Frase[i] == "D":
            Convertido = Convertido + "14"
        if Frase[i] == "E":
            Convertido = Convertido + "15"
        if Frase[i] == "F":
            Convertido = Convertido + "16"
        if Frase[i] == "G":
            Convertido = Convertido + "17"
        if Frase[i] == "H":
            Convertido = Convertido + "18"
        if Frase[i] == "I":
            Convertido = Convertido + "19"
        if Frase[i] == "J":
            Convertido = Convertido + "21"
        if Frase[i] == "K":
            Convertido = Convertido + "22"
        if Frase[i] == "L":
            Convertido = Convertido + "23"
        if Frase[i] == "M":
            Convertido = Convertido + "24"
        if Frase[i] == "N":
            Convertido = Convertido + "25"
        if Frase[i] == "O":
            Convertido = Convertido + "26"
        if Frase[i] == "P":
            Convertido = Convertido + "27"
        if Frase[i] == "Q":
            Convertido = Convertido + "28"
        if Frase[i] == "R":
            Convertido = Convertido + "29"
        if Frase[i] == "S":
            Convertido = Convertido + "31"
        if Frase[i] == "T":
            Convertido = Convertido + "32"
        if Frase[i] == "U":
            Convertido = Convertido + "33"
        if Frase[i] == "V":
            Convertido = Convertido + "34"
        if Frase[i] == "W":
            Convertido = Convertido + "35"
        if Frase[i] == "X":
            Convertido = Convertido + "36"
        if Frase[i] == "Y":
            Convertido = Convertido + "37"
        if Frase[i] == "Z":
            Convertido = Convertido + "38"
        if Frase[i] == "0":
            Convertido = Convertido + "41"
        if Frase[i] == "1":
            Convertido = Convertido + "42"
        if Frase[i] == "2":
            Convertido = Convertido + "43"
        if Frase[i] == "3":
            Convertido = Convertido + "44"
        if Frase[i] == "4":
            Convertido = Convertido + "45"
        if Frase[i] == "5":
            Convertido = Convertido + "46"
        if Frase[i] == "6":
            Convertido = Convertido + "47"
        if Frase[i] == "7":
            Convertido = Convertido + "48"
        if Frase[i] == "8":
            Convertido = Convertido + "49"
        if Frase[i] == "9":
            Convertido = Convertido + "51"
        if Frase[i] == " ":
            Convertido = Convertido + "99"
    return Convertido

# Este método escolhe um número entre 0 e o tamanho da lista de primos
def Calcula_Random(Tamanho):
    random.seed(datetime.datetime.now().microsecond)
    posicao = random.randint(0, Tamanho)
    return posicao

# Este método calcula a chave pública n
def Calcula_n():
    lista_primos = [11, 17, 23, 29, 41, 47, 53, 59, 71, 83, 89]
    Tamanho = len(lista_primos) - 1
    posicao_01 = Calcula_Random(Tamanho)
    posicao_02 = Calcula_Random(Tamanho)
    while posicao_02 == posicao_01:
        posicao_02 = Calcula_Random(Tamanho)
    p = lista_primos[posicao_01]
    q = lista_primos[posicao_02]
    n = p * q
    return n, p, q

# Este método separa a string de números em blocos, para a codificação
def Separa_String(Convertido):
    contador = 1
    Codigo = []
    Caracteres = ""
    for i in range(len(Convertido)):
        Caracteres = Caracteres + Convertido[i]
        contador += 1
        if contador == 3:
            Codigo.append(int(Caracteres))
            Caracteres = ""
            contador = 1
    return Codigo
