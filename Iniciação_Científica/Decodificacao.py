# Este código tem função inversa ao da Pré-codificação e codificação, 
# revertendo o código numérico em texto legível

# Este método calcula k, que será usado em outro processo da decodificação
def Calcula_k(p, q):
    k = ((p - 1) * (q - 1) + 2) / 6
    k = int(k)
    return k

# Este método calcula d, que será usado em outra etapa da decodificação
def Calcula_d(k):
    d = 4 * k - 1
    d = int(d)
    return d

# Este método calcula os restos pedidos pela função Decodifica, utilizando d e n 
def Calcula_Resto(Codigo, d, p, q):
    Auxiliar = Codigo ** d
    n = p * q
    Decodificado = Auxiliar % n
    Decodificado = int(Decodificado)
    return Decodificado

# Este é o método principal da Decodificação, devolvendo a mensagem em forma numérica
def Decodifica(Lista, p, q):
    k = Calcula_k(p, q)
    d = Calcula_d(k)
    Lista_Temporaria = []
    for i in range(len(Lista)):
        Numero = Calcula_Resto(Lista[i], d, p, q)
        Lista_Temporaria.append(Numero)
    return Lista_Temporaria

# Este método troca os números da lista por suas letras correspondentes, 
# devolvendo a mensagem original
def Troca_Numeros(Lista_Temporaria):
    Frase_Original = ""
    for i in range(len(Lista_Temporaria)):
        if Lista_Temporaria[i] == 11:
            Frase_Original = Frase_Original + "A"
        if Lista_Temporaria[i] == 12:
            Frase_Original = Frase_Original + "B"
        if Lista_Temporaria[i] == 13:
            Frase_Original = Frase_Original + "C"
        if Lista_Temporaria[i] == 14:
            Frase_Original = Frase_Original + "D"
        if Lista_Temporaria[i] == 15:
            Frase_Original = Frase_Original + "E"
        if Lista_Temporaria[i] == 16:
            Frase_Original = Frase_Original + "F"
        if Lista_Temporaria[i] == 17:
            Frase_Original = Frase_Original + "G"
        if Lista_Temporaria[i] == 18:
            Frase_Original = Frase_Original + "H"
        if Lista_Temporaria[i] == 19:
            Frase_Original = Frase_Original + "I"
        if Lista_Temporaria[i] == 21:
            Frase_Original = Frase_Original + "J"
        if Lista_Temporaria[i] == 22:
            Frase_Original = Frase_Original + "K"
        if Lista_Temporaria[i] == 23:
            Frase_Original = Frase_Original + "L"
        if Lista_Temporaria[i] == 24:
            Frase_Original = Frase_Original + "M"
        if Lista_Temporaria[i] == 25:
            Frase_Original = Frase_Original + "N"
        if Lista_Temporaria[i] == 26:
            Frase_Original = Frase_Original + "O"
        if Lista_Temporaria[i] == 27:
            Frase_Original = Frase_Original + "P"
        if Lista_Temporaria[i] == 28:
            Frase_Original = Frase_Original + "Q"
        if Lista_Temporaria[i] == 29:
            Frase_Original = Frase_Original + "R"
        if Lista_Temporaria[i] == 31:
            Frase_Original = Frase_Original + "S"
        if Lista_Temporaria[i] == 32:
            Frase_Original = Frase_Original + "T"
        if Lista_Temporaria[i] == 33:
            Frase_Original = Frase_Original + "U"
        if Lista_Temporaria[i] == 34:
            Frase_Original = Frase_Original + "V"
        if Lista_Temporaria[i] == 35:
            Frase_Original = Frase_Original + "W"
        if Lista_Temporaria[i] == 36:
            Frase_Original = Frase_Original + "X"
        if Lista_Temporaria[i] == 37:
            Frase_Original = Frase_Original + "Y"
        if Lista_Temporaria[i] == 38:
            Frase_Original = Frase_Original + "Z"
        if Lista_Temporaria[i] == 41:
            Frase_Original = Frase_Original + "0"
        if Lista_Temporaria[i] == 42:
            Frase_Original = Frase_Original + "1"
        if Lista_Temporaria[i] == 43:
            Frase_Original = Frase_Original + "2"
        if Lista_Temporaria[i] == 44:
            Frase_Original = Frase_Original + "3"
        if Lista_Temporaria[i] == 45:
            Frase_Original = Frase_Original + "4"
        if Lista_Temporaria[i] == 46:
            Frase_Original = Frase_Original + "5"
        if Lista_Temporaria[i] == 47:
            Frase_Original = Frase_Original + "6"
        if Lista_Temporaria[i] == 48:
            Frase_Original = Frase_Original + "7"
        if Lista_Temporaria[i] == 49:
            Frase_Original = Frase_Original + "8"
        if Lista_Temporaria[i] == 51:
            Frase_Original = Frase_Original + "9"
        if Lista_Temporaria[i] == 99:
            Frase_Original = Frase_Original + " "
    return Frase_Original
