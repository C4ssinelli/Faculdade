// Nome: Alex Luiz Domingues Cassinelli, 
// RA: 211021849
// Sistema Operacional: Windows 10
// Linguagem: C++ (utilizado pela facilidade de manipulacao de strings)
// Compilador: g++, usando o WSL

/* Tabelas utilizadas, para facilitar a compreensao

	Tabela de Simbolos Especiais:
		',' = ','
		'.' = '.'
		':' = ':'
		';' = ';'
		':=' = ':='
		'*' = '*'
		'-' = '-'
		'+' = '+'
		'(' = '('
		')' = ')'
		'>' = '>'
		'<' = '<'
		
	Tabela de Palavras Reservadas:
		"program" 	= 	"P"
    	"var" 		= 	"V"
	    "integer" 	= 	"I"
	    "procedure" = 	"Y"
	    "begin" 	= 	"B"
	    "if" 		= 	"C"
	    "div" 		= 	"D"
	    "then" 		= 	"T"
	    "else" 		= 	"N"
	    "end" 		=	"F"
	    "read" 		= 	"R"
	    "while" 	= 	"Q"
	    "do" 		= 	"O"
	    "write" 	= 	"W"
        "or"        =   "U"
        "and"       =   "E"
        "not"       =   "M"
        "boolean"   =   "X"
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<fstream>
using namespace std;

map<string, string> IDs;
string Unidade = "0";
string Dezena = "0";
string Leitura;
string Proximo;
FILE *Arquivo;
char Recebe_Leitura[150];
int Posicao_na_Linha, Contador_de_Linhas = 1;

char Simbolos_Especiais[] = {',', '.', ':',';', '=', '*', '-', '+', '(', ')', '>', '<'};
char Letras_Minusculas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Letras_Maiusculas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char Digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string Palavras_Reservadas[] = {"program", "var", "integer", "procedure", "begin", "if", "div", "then", "else", "end", "read", "while", "do", "write", "boolean"};

bool Verifica_Simbolo(string Caracter_Atual);

bool Verifica_Letra(string Caracter_Atual);

bool Verifica_Digito(string Caracter_Atual);

bool Verifica_Palavra_Reservada(string Caracter_Atual);

char PROXIMO(string Resultado_Leitura, int Posicao_Atual);

string CODIGO(string Codigo);

void ERRO(int Linha, int Tipo_de_Erro);

int PROGRAMA();

int BLOCO();

int PARTE_DECLARACAO_VARIAVEIS();

int DECLARACAO_VARIAVEIS();

int LISTA_IDENTIFICADORES();

int PARTE_DECLARACAO_SUB_ROTINAS();

int DECLARACAO_PROCEDIMENTO();

int DECLARACAO_FUNCAO();

int PARAMETROS_FORMAIS();

int SECAO_PARAMETROS_FORMAIS();

int COMANDO_COMPOSTO();

int COMANDO();

int COMANDO_SEM_ROTULO();

int ATRIBUICAO();

int CHAMADA_PROCEDIMENTO();

int COMANDO_CONDICIONAL();

int COMANDO_REPETITIVO();

int LISTA_EXPRESSOES();

int EXPRESSAO();

int RELACAO();

int EXPRESSAO_SIMPLES();

int TERMO();

int FATOR();

int VARIAVEL();

int CHAMADA_FUNCAO();

int NUMERO();

int DIGITO();

int IDENTIFICADOR();

int LETRA();

int main()
{
    ofstream Arquivo_Auxiliar;
    Arquivo_Auxiliar.open("Auxiliar.txt");
    string Resultado;

    Arquivo = fopen("Exemplo1_Trab2_Compiladores.txt", "rt");
    if(Arquivo == NULL)
    {
        cout << "Erro na abertura do arquivo\n";
        return 0;
    }

    while(feof(Arquivo) == false)
    {
        Resultado = fgets(Recebe_Leitura, 150, Arquivo);
        if(Resultado.empty() == false)
        {
            Proximo = Resultado[0];
            Posicao_na_Linha = 0;
            while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Resultado.size())
            {
                string Atomo, Simbolo;
                if(Proximo == " ")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Resultado, Posicao_na_Linha);
                    continue;
                }
                else if(Proximo == "\t")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Resultado, Posicao_na_Linha);
                    continue;
                }
                else if(Verifica_Simbolo(Proximo) == true)
                {
                    string S = Proximo;
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Resultado, Posicao_na_Linha);
                    if(S == ":" && Proximo == "=")
                    {
                        S = ":=";
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Resultado, Posicao_na_Linha);
                    }
                    Simbolo = CODIGO(S);
                }
                else if(Verifica_Letra(Proximo) == true)
                {
                    do
                    {
                        Atomo += Proximo;
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Resultado, Posicao_na_Linha);
                    }
                    while(Verifica_Letra(Proximo) || Verifica_Digito(Proximo));
                    Simbolo = CODIGO(Atomo);
                }
                else if(Verifica_Digito(Proximo))
                {
                    do
                    {
                        Atomo += Proximo;
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Resultado, Posicao_na_Linha);
                    } 
                    while (Verifica_Digito(Proximo));
                    if(Verifica_Letra(Proximo))
                    {
                        ERRO(Contador_de_Linhas, 1);
                        return 0;
                    }
                    Simbolo = Atomo;
                }
                else
                {
                    ERRO(Contador_de_Linhas, 2);
                    return 0;
                }
                Arquivo_Auxiliar << Simbolo;
            }
            Arquivo_Auxiliar << "\n";
        }
        Contador_de_Linhas++;
    }
    fclose(Arquivo);
    Arquivo_Auxiliar.close();

    Arquivo = fopen("Auxiliar.txt", "rt");
    if(Arquivo == NULL)
    {
        cout << "Erro na abertura do arquivo\n";
        return 0;
    }
    Leitura = fgets(Recebe_Leitura, 150, Arquivo);
    Contador_de_Linhas = 1;
    int Verifica_Compilacao = PROGRAMA();
    if(Verifica_Compilacao == 1)
        cout << "\nO programa foi compilado com sucesso.\n\n";
    else
        ERRO(Contador_de_Linhas, 3);
    
    return 0;
}

bool Verifica_Simbolo(string Caracter_Atual)
{
	char Simbolo = Caracter_Atual[0];
	for(int i = 0; i < 12; i++)
		if(Simbolo == Simbolos_Especiais[i])
			return true;
	return false;
}

bool Verifica_Letra(string Caracter_Atual)
{
	char Letra = Caracter_Atual[0];
	for(int i = 0; i < 26; i++)
	{
		if(Letra == Letras_Minusculas[i])
			return true;
		else if(Letra == Letras_Maiusculas[i])
			return true;
	}
	return false;
}

bool Verifica_Digito(string Caracter_Atual)
{
	char Digito = Caracter_Atual[0];
	for(int i = 0; i < 10; i++)
		if(Digito == Digitos[i])
			return true;
	return false;
}

bool Verifica_Palavra_Reservada(string Caracter_Atual)
{
	for(int i = 0; i < 15; i++)
		if(Caracter_Atual == Palavras_Reservadas[i])
			return true;
	return false;
}

char PROXIMO(string Resultado_Leitura, int Posicao_Atual)
{
    if(Proximo == "\n" && Posicao_Atual != 0)
    {
        if(feof(Arquivo) == false)
        {
            Contador_de_Linhas++;
            Resultado_Leitura = fgets(Recebe_Leitura, 150, Arquivo);
            Leitura = Resultado_Leitura;
            Posicao_Atual = 0;
            Posicao_na_Linha = 0;
        }
    }
    return Resultado_Leitura[Posicao_Atual];
}

string CODIGO(string Codigo)
{
    if(Codigo == "program")
        Codigo = "P";
    else if(Codigo == "var")
        Codigo = "V";
    else if(Codigo == "integer")
        Codigo = "I";
    else if(Codigo == "procedure")
        Codigo = "Y";
    else if(Codigo == "begin")
        Codigo = "B";
    else if(Codigo == "if")
        Codigo = "C";
    else if(Codigo == "div")
        Codigo = "D";
    else if(Codigo == "then")
        Codigo = "T";
    else if(Codigo == "else")
        Codigo = "N";
    else if(Codigo == "end")
        Codigo = "F";
    else if(Codigo == "read")
        Codigo = "R";
    else if(Codigo == "while")
        Codigo = "Q";
    else if(Codigo == "do")
        Codigo = "O";
    else if(Codigo == "write")
        Codigo = "W";
    else if(Codigo == "or")
        Codigo = "U";
    else if(Codigo == "and")
        Codigo = "E";
    else if(Codigo == "not")
        Codigo = "M";
    else if(Codigo == "boolean")
        Codigo = "X";
    else if(Verifica_Simbolo(Codigo))
        return Codigo;
    else if(IDs.count(Codigo))
    {
        Codigo = IDs[Codigo];
    }
    else
    {
        string ID_Novo;
        if(Unidade == "9")
        {
            Unidade = "0";
            Dezena[0]++;
        }
        else
            Unidade[0]++;
        
        if(Dezena == "0")
            ID_Novo = "ID" + Unidade;
        else
            ID_Novo = "ID" + Dezena + Unidade;
        IDs[Codigo] = ID_Novo;
        Codigo = ID_Novo;
    }
    return Codigo;
}

void ERRO(int Linha, int Tipo_de_Erro)
{
	if(Tipo_de_Erro == 1)
		cout << "\n\nErro na linha #" << Linha << ": Numero mal formado.\n\n";
	else if(Tipo_de_Erro == 2)
		cout << "\n\nErro na linha #" << Linha << ": Caractere invalido.\n\n";
    else
        cout << "\n\nErro na linha #" << Linha << ": Erro de sintaxe.\n\n";
}

int PROGRAMA()
{
    if(Leitura.empty() == false)
    {
        Proximo = Leitura[0];
        Posicao_na_Linha = 0;
        while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
        {
            if(Proximo == " ")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                cout << " ";
                continue;
            }
            else if(Proximo == "\t")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                continue;
            }
            else if(Verifica_Letra(Proximo) == true)
            {
                if(Proximo == "P")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                    if(IDENTIFICADOR() == true)
                        return BLOCO();
                    else
                        return 0;
                    
                }
            }
        }
    }
    return 0;
}

int IDENTIFICADOR()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Verifica_Letra(Proximo) == true)
        {
            if(Proximo == "I")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                if(Proximo == "D")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                    if(Verifica_Digito(Proximo) == true)
                    {
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                        while(Verifica_Digito(Proximo) == true)
                        {
                            Posicao_na_Linha++;
                            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                        }
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    return 0;
}

int BLOCO()
{
    if(PARTE_DECLARACAO_VARIAVEIS() == false)
        return 0;
    PARTE_DECLARACAO_SUB_ROTINAS();
    return COMANDO_COMPOSTO();
}

int DECLARACAO_VARIAVEIS()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == " \t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        while(Proximo == "I")
        {
            if(LISTA_IDENTIFICADORES() == true)
            {
                if(Proximo == ":")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                }
                else
                    return 0;
                if(Proximo == "I" || Proximo == "X")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                    if(Proximo == ";")
                    {
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                    }
                    else
                        return 0;
                    if(feof(Arquivo) == false)
                    {
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                        if(Proximo != "I")
                            return 1;
                    }
                    else
                        return 1;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
    }

    return 0;
}

int LISTA_IDENTIFICADORES()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        while(Proximo != ":" && Proximo != "\n")
        {
            if(IDENTIFICADOR() == true)
            {
                if(Proximo == ",")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                }
                else
                {
                    if(Proximo != ":")
                        return 0;
                }
            }
        }
        return 1;
    }

    return 0;
}

int PARTE_DECLARACAO_VARIAVEIS()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Verifica_Letra(Proximo) == true)
        {
            if(Proximo == "V")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                return DECLARACAO_VARIAVEIS();
            }
        }
    }

    return 0;
}

int DECLARACAO_PROCEDIMENTO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Verifica_Letra(Proximo) == true)
        {
            if(Proximo == "Y")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                if(IDENTIFICADOR() == true)
                {
                    if(Proximo == ";")
                    {
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                        return BLOCO();
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
    }

    return 0;
}

int PARTE_DECLARACAO_SUB_ROTINAS()
{
    return DECLARACAO_PROCEDIMENTO();
}

int COMANDO_COMPOSTO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Verifica_Letra(Proximo) == true)
        {
            if(Proximo == "B")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                while(Proximo != "F")
                {
                    if(COMANDO() == false)
                        return 0;
                    if(Proximo != ";" && Proximo != "\n" && Proximo != "F")
                        return 0;
                    else
                    {
                        if(Proximo != "F")
                        {
                            Posicao_na_Linha++;
                            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                        }
                    }
                    if(Proximo == "\n")
                    {
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                    }
                }
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                if(Proximo == ";" || Proximo == ".")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                }
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }

    return 0;
}

int COMANDO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Verifica_Digito(Proximo) == false)
            return COMANDO_SEM_ROTULO();
    }

    return 0;
}

int COMANDO_SEM_ROTULO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Verifica_Digito(Proximo) == false)
            return( ATRIBUICAO()            || 
                    CHAMADA_PROCEDIMENTO()  || 
                    COMANDO_COMPOSTO()      ||
                    COMANDO_CONDICIONAL()   ||
                    COMANDO_REPETITIVO());
    }

    return 0;
}

int ATRIBUICAO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(VARIAVEL() == true)
        {
            if(Proximo == ":")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                if(Proximo == "=")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                    return EXPRESSAO();
                }
                else
                    return 0;
            }
            else
            {
                while(Proximo != "I")
                {
                    Posicao_na_Linha--;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                }
                return 0;
            }
        }
        else
            return 0;
    }

    return 0;
}

int EXPRESSAO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(EXPRESSAO_SIMPLES() == true)
        {
            while(RELACAO() == true)
            {
                if(EXPRESSAO_SIMPLES() == false)
                    return 0;
            }
            return 1;
        }
        else
            return 0;
    }

    return 0;
}

int EXPRESSAO_SIMPLES()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "+" || Proximo == "-")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
        }
        if(TERMO() == false)
            return 0;
        else
        {
            while(Proximo == "+" || Proximo == "-" || Proximo == "U")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                if(TERMO() == false)
                    return 0;
            }
            return 1;
        }
    }

    return 0;
}

int TERMO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(FATOR() == false)
            return 0;
        else
        {
            while(Proximo == "*" || Proximo == "D" || Proximo == "E")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                if(FATOR() == false)
                    return 0;
            }
            return 1;
        }
    }

    return 0;
}

int FATOR()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(VARIAVEL() == true || NUMERO() == true)
            return 1;
        else if(Proximo == "(")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            if(EXPRESSAO() == false)
                return 0;
            if(Proximo == ")")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }

    return 0;
}

int RELACAO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(Proximo == "=")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            return 1;
        }
        else if(Proximo == "<")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            if(Proximo == "=" || Proximo == ">")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            }
            return 1;
        }
        else if(Proximo == ">")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            if(Proximo == "=")
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            }
            return 1;
        }
        else
            return 0;
    }

    return 0;
}

int VARIAVEL()
{
    return IDENTIFICADOR();
}

int CHAMADA_PROCEDIMENTO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(IDENTIFICADOR())
        {
            while(Proximo != ";")
            {
                if(LISTA_EXPRESSOES() == false)
                    return 0;
                if(Proximo == ",")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                }
                else if(Proximo != ";")
                {
                    return 0;
                }
            }
            return 1;
        }
        else if(Proximo == "R")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            while(Proximo != ";")
            {
                if(LISTA_EXPRESSOES() == false)
                    return 0;
                if(Proximo == ",")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                }
                else if(Proximo != ";")
                    return 0;
            }
            return 1;
        }
        else if(Proximo == "W")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            while(Proximo != ";")
            {
                if(LISTA_EXPRESSOES() == false)
                    return 0;
                if(Proximo == ",")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                }
                else if(Proximo != ";")
                    return 0;
            }
            return 1;
        }
        else
            return 0;
    }

    return 0;
}

int COMANDO_CONDICIONAL()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(Proximo == "C")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            if(EXPRESSAO() == true)
            {
                if(Proximo == "T")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                    if(COMANDO_SEM_ROTULO())
                    {
                        if(Proximo == ";")
                        {
                            Posicao_na_Linha++;
                            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                            if(Proximo == "\n")
                            {
                                Posicao_na_Linha++;
                                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                            }
                        }
                        else
                            return 0;
                        if(Proximo == "N")
                        {
                            Posicao_na_Linha++;
                            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                            if(COMANDO_SEM_ROTULO())
                            {
                                if(Proximo == ";")
                                {
                                    Posicao_na_Linha++;
                                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                                }
                                else
                                    return 0;
                                return 1;
                            }
                            return 0;
                        }
                        return 1;
                    }
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }

    return 0;
}

int COMANDO_REPETITIVO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(Proximo == "Q")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            if(EXPRESSAO() == true)
            {
                if(Proximo == "O")
                {
                    Posicao_na_Linha++;
                    Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                    if(COMANDO_SEM_ROTULO())
                    {
                        Posicao_na_Linha++;
                        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }

    return 0;
}

int NUMERO()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(Verifica_Digito(Proximo) == true)
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            while(Verifica_Digito(Proximo))
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            }
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int LISTA_EXPRESSOES()
{
    if(Proximo == "\n")
    {
        Posicao_na_Linha++;
        Proximo = PROXIMO(Leitura, Posicao_na_Linha);
    }
    while(Proximo != "\n" && Proximo != "\r" && Posicao_na_Linha < Leitura.size())
    {
        if(Proximo == " ")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        else if(Proximo == "\t")
        {
            Posicao_na_Linha++;
            Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            continue;
        }
        if(EXPRESSAO() == true)
        {
            while(EXPRESSAO() == true)
            {
                Posicao_na_Linha++;
                Proximo = PROXIMO(Leitura, Posicao_na_Linha);
            }
            return 1;
        }
        else
            return 0;
    }
    
    return 0;
}