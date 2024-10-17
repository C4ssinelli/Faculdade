# Este código tem o objetivo de codificar a mensagem, propriamente dita
import Pre_Cod

# Este método calcula o resto da divisão, este é o método de codificação
def Calcula_Resto(Numero, n):
    Alvo = Numero ** 3
    Resto = Alvo % n
    return Resto

# Este é o método que será chamado quando se desejar que o texto seja codificado
def Transformar(Frase, n):
    Convertido = Pre_Cod.Conversao(Frase)
    Codigo = Pre_Cod.Separa_String(Convertido)
    Novo_Codigo = []
    for i in range (len(Codigo)):
        Numero = Codigo[i]
        Novo_Numero = Calcula_Resto(Numero, n)
        Novo_Codigo.append(Novo_Numero)
        Codigo_Str = ""
        for i in range(len(Novo_Codigo)):
            Codigo_Str += str(Novo_Codigo[i])
            if i != len(Novo_Codigo) - 1:
                Codigo_Str += " "
    return Codigo_Str
