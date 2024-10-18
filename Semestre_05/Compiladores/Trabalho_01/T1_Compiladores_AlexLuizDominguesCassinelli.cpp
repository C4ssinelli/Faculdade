// Nome: Alex Luiz Domingues Cassinelli, 
// RA: 211021849
// Sistema Operacional: Windows 7 Professional
// Linguagem: C++ (utilizado pela facilidade de manipulacao de strings)
// Compilador: Dev-C++ (versão 5.11)

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
		"program" 	= 	"PROGRAM"
    	"var" 		= 	"VAR"
	    "integer" 	= 	"INTEGER"
	    "procedure" = 	"PROCEDURE"
	    "begin" 	= 	"BEGIN"
	    "if" 		= 	"IF"
	    "div" 		= 	"DIV"
	    "then" 		= 	"THEN"
	    "else" 		= 	"ELSE"
	    "end" 		=	"END"
	    "read" 		= 	"READ"
	    "while" 	= 	"WHILE"
	    "do" 		= 	"DO"
	    "write" 	= 	"WRITE"
*/

#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<vector>
using namespace std;

// Vetores para facilitar a visualizacao das verificacoes

char Simbolos_Especiais[] = {',', '.', ':',';', '=', '*', '-', '+', '(', ')', '>', '<'};
char Letras_Minusculas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Letras_Maiusculas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char Digitos[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string Palavras_Reservadas[] = {"program", "var", "integer", "procedure", "begin", "if", "div", "then", "else", "end", "read", "while", "do", "write"};
string Palavras_Usadas[] = {"PROGRAM", "VAR", "INTEGER", "PROCEDURE", "BEGIN", "IF", "DIV", "THEN", "ELSE", "END", "READ", "WHILE", "DO", "WRITE"};
vector<string> Tabela_de_Simbolos;

// Fim dos vetores

// Funcoes auxiliares

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
	for(int i = 0; i < 14; i++)
		if(Caracter_Atual == Palavras_Reservadas[i])
			return true;
	return false;
}

// Fim das funcoes auxiliares

// Funcao PROXIMO
char PROXIMO(string Leitura, int Posicao_na_Linha)
{
	return Leitura[Posicao_na_Linha];
}

// Funcao CODIGO
string CODIGO(string Codigo)
{
	for(int i = 0; i < 14; i++)
		if(Codigo == Palavras_Reservadas[i])
			return Codigo = Palavras_Usadas[i];
	if(Verifica_Simbolo(Codigo) == true)
	{
		for(int i = 0; i < 12; i++)
			if(Codigo[0] == Simbolos_Especiais[i])
			{
				return Codigo;
			}
	}
	for(int i = 0; i < Tabela_de_Simbolos.size(); i++)
	{
		if(Codigo == Tabela_de_Simbolos[i])
		{
			return Tabela_de_Simbolos[i];
		}
	}
	Tabela_de_Simbolos.push_back(Codigo);
	return Codigo;
}

// Funcao ERRO
void ERRO(int Linha, int Tipo_de_Erro)
{
	if(Tipo_de_Erro == 1)
		cout << "\n\nErro na linha #" << Linha << ": Numero mal formado.\n\n";
	else
		cout << "\n\nErro na linha #" << Linha << ": Caractere invalido.\n\n";
}

int main()
{
	FILE *Arquivo;
	ofstream Arquivo_Saida;
	char Recebe_Leitura[150];
	string Leitura, Caracter_Atual;
	int Contador_de_Linhas = 1, Posicao_na_Linha;
	bool Checagem = false;
	// Abertura do arquivo txt
	Arquivo = fopen("Trab1_Compiladores.txt", "rt");
	if(Arquivo == NULL)										// Se a abertura teve algum problema na abertura do arquivo
	{
		cout << "Houve problema na abertura do arquivo.\n";
		return 0;
	}
	Arquivo_Saida.open("Trab1_Compiladores_Saida.txt");
	if(Arquivo_Saida == NULL)
	{
		cout << "Houve problema na abertura do arquivo de saida.\n";
		return 0;
	}
	while(!feof(Arquivo))
	{
		string Saida;
		Leitura = fgets(Recebe_Leitura, 150, Arquivo);		// Leitura da Linha
		if(Leitura.empty() == false)						// Se nao houve problemas na leitura
		{
			Caracter_Atual = Leitura[0];
			Posicao_na_Linha = 0;
			
			while(Caracter_Atual != "\n" && Caracter_Atual != "\r" && Posicao_na_Linha < Leitura.size())
			{
				string Atomo, Simbolo;
				if(Caracter_Atual == " ")
				{
					Posicao_na_Linha++;
					Caracter_Atual = PROXIMO(Leitura, Posicao_na_Linha);
					Saida += " ";
					continue;
				}
				else if(Caracter_Atual == "\t")
				{
					Posicao_na_Linha++;
					Caracter_Atual = PROXIMO(Leitura, Posicao_na_Linha);
					continue;
				}
				else if(Verifica_Simbolo(Caracter_Atual) == true)
				{
					string Teste_Atribuicao = Caracter_Atual;
					Posicao_na_Linha++;
					Caracter_Atual = PROXIMO(Leitura, Posicao_na_Linha);
					if(Teste_Atribuicao == ":" && Caracter_Atual == "=")
					{
						Teste_Atribuicao = ":=";
						Posicao_na_Linha++;
						Caracter_Atual = PROXIMO(Leitura, Posicao_na_Linha);
					}
					Simbolo = CODIGO(Teste_Atribuicao);
				}
				else if(Verifica_Letra(Caracter_Atual) == true)
				{
					do
					{
						Atomo += Caracter_Atual;
						Posicao_na_Linha++;
						Caracter_Atual = PROXIMO(Leitura, Posicao_na_Linha);
					}
					while(Verifica_Letra(Caracter_Atual) == true || Verifica_Digito(Caracter_Atual) == true);
					
					Simbolo = CODIGO(Atomo);
				}
				else if(Verifica_Digito(Caracter_Atual) == true)
				{
					do
					{
						Atomo += Caracter_Atual;
						Posicao_na_Linha++;
						Caracter_Atual = PROXIMO(Leitura, Posicao_na_Linha);
					}
					while(Verifica_Digito(Caracter_Atual));
					
					if(Verifica_Letra(Caracter_Atual) == true)
					{
						ERRO(Contador_de_Linhas, 1);
						Checagem = true;
						continue;
					}
					
					Simbolo = CODIGO(Atomo);
				}
				else
				{
					ERRO(Contador_de_Linhas, 2);
					Posicao_na_Linha++;
					Caracter_Atual = PROXIMO(Leitura, Posicao_na_Linha);
					Checagem = true;
					continue;
				}
				
				Saida += Simbolo;
			}
		}
		if(Arquivo_Saida.is_open() && Checagem == false)
		{
			Arquivo_Saida << Contador_de_Linhas << ". " << Saida << "\n";
		}
		Contador_de_Linhas++;
	}
	fclose(Arquivo);
	Arquivo_Saida.close();
	
	if(Checagem == false)
	{
		cout << "\n\nAnalise lexica realizada com sucesso.\n";
		cout << "Por favor, verificar arquivo de nome Trab1_Compiladores_Saida.txt.\n";
	}
	
	else
	{
		cout << "\nFalha na analise.\n";
		cout << "Por favor, olhar nas linhas descritas acima.\n";
		cout << "Para evitar confusao, o arquivo de saida nao foi concluido.\n";
	}
	
	return 0;
}
