// Este trabalho foi desenvolvido em conjunto com Matheus Herminio da Silva.
// Ele age como um banco de dados para um RH, além de criptografar arquivos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <locale.h>
#include <winbase.h>

#define Baixo 80
#define Cima 72
#define Enter 13
#define Esc 27
#define f1 59

// Feito Por: Alex Luiz Domingues Cassinelli (RA:211021849) e Matheus Herminio da Silva (RA:201027747) 
// BCC 2021 

//Menu para cursor---------------------------------------------------------------------------------------------------------------------------------------------

void gotoxy (int x, int y) 
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//Define onde o cursor vai estar

int Troca_Cor(char Cor) 
{
  HANDLE h;
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h, Cor);
}//Troca a cor das letras da tela

void Escreve_Texto(int x, int y, char texto[], int cor)
{
  Troca_Cor(cor);
  gotoxy(y,x);
  printf("%s",texto);
}//Escreve o texto do menu na tela (opcoes)

void Menu_Principal (int Opcao)
{
	char Mensagem[] = {"Por favor, selecione uma opcao para o programa fazer"}, vet[][100] = {"Adicionar funcionarios", "Consultar dados de um funcionario", "Alterar dados de um funcionario", "Suspender ou demitir um funcionario", "Alterar a data do sistema", "Alterar o horario do sistema", "Criar pasta", "Renomear pasta", "Renomear arquivo", "Excluir arquivo"};
	int i;
	system ("cls");
	Escreve_Texto(0, 5, Mensagem, 15);
	for (i = 0; i < 10; i++)
	{
		Escreve_Texto(3 + i, 10, vet[i], 3);
	}
	Escreve_Texto(2 + Opcao, 10, vet[Opcao - 1], 15);
	Escreve_Texto(13, 10, "Pressione F1 para receber ajuda", 7);
	Escreve_Texto(14, 10, "Pressione Esc para sair", 7);
}//Estrutura do menu

void Menuzinho_01(int Opcao)
{
	char Mensagem[] = {"Por favor, selecione uma opcao para pesquisar o funcionario"}, vet[][100] = {"Nome", "ID"};
	int i;
	system ("cls");
	Escreve_Texto(0, 5, Mensagem, 15);
	for (i = 0; i < 2; i++)
	{
		Escreve_Texto(3 + i, 10, vet[i], 3);
	}
	Escreve_Texto(2 + Opcao, 10, vet[Opcao - 1], 15);
	Escreve_Texto(13, 10, "Pressione F1 para receber ajuda", 7);
}

void Menuzinho_02(int Opcao)
{
	char Mensagem[] = {"Por favor, selecione se quer utilizar a exclusao fisica ou logica um funcionario"}, vet[][100] = {"Fisica", "Logica"};
	int i;
	system ("cls");
	Escreve_Texto(0, 5, Mensagem, 15);
	for (i = 0; i < 2; i++)
	{
		Escreve_Texto(3 + i, 10, vet[i], 3);
	}
	Escreve_Texto(2 + Opcao, 10, vet[Opcao - 1], 15);
	Escreve_Texto(13, 10, "Pressione F1 para receber ajuda", 7);
}

//Fim do menu--------------------------------------------------------------------------------------------------------------------------------------------------

void type(const char * p){
	
	
	if (NULL == p)
		return;
		
	while (*p){
		
		printf("%c\xDB", *p++);
		
		::Sleep(25);
		
		printf("\b \b"); 
		
		::Sleep(25);
		
		}
		::Sleep(250);
}  // Faz a anima��o de digitar no type

void apresentacao(){
	
	struct tm *data_hora_atual;     
  time_t segundos;
  
  time(&segundos);   
  
  data_hora_atual = localtime(&segundos);  
  
	type("Ola usuario! \n\n");
	type("Sou um programa para manipulacao de arquivos! \n \n");
	type("Agradeco sua escolha!!\n\n");
	
	
  type("Data de hoje: ");
  printf("%d/", data_hora_atual->tm_mday);  
  printf("%d/", data_hora_atual->tm_mon+1);
  printf("%d\n\n", data_hora_atual->tm_year+1900);  
  
  
	Sleep(3000);
	
	system("cls");
	
} // Apresenta��o do arquivo no inicio


void prompt(char cmd[300])
{
    system(cmd);
} // abre o prompt de comando

void caminho()
{
	char n_caminho[300];
	printf("%s\n", getcwd(n_caminho, 300));
} // caminho pra chegar no arquivo


void dir(char caminho[296])
{
	chdir(caminho);
}

void renomear(char n1[], char n2[])
{
	 
    int ok;
    ok = rename(n1, n2);
    if(!ok)
    {
        printf("%s", "Arquivo renomeado com sucesso");
    }
    else
    {
        perror("Ops... Algo Deu Errado");
    }
   
} // Renomea Arquivo

void excluiArq(char n1[])
{
	 
    int ok;
    ok = remove(n1);
    if(!ok)
    {
        printf("%s", "Arquivo removido com sucesso");
    }
    else
    {
        perror("Ops... Algo Deu Errado");
    }
    
} // exclui arquivos

void renamePasta(char n1[], char n2[])
{
	 
    int F;
    F = rename(n1, n2);
    if(!F)
    {
        printf("%s", "A pasta foi renomeada com sucesso! ");
    }
    else
    {
        perror("Ops... Algo Deu Errado");
        getch();
    }
   
} // renomeia as pastas

void novaPasta(char n1[])
{
	int ok;
	ok = mkdir(n1);
	if(!ok)
    {
        printf("%s", "A pasta foi criada com sucesso! ");
    }
    else
    {
        perror("Ops... Algo Deu Errado");
    }
} // cria uma nova pasta

int Criptografa()
{
	char Texto;
	FILE *Arquivo, *Cripto;
	if((Arquivo = fopen("Ajuda.txt", "r")) == NULL)
	{
		printf("Errou");
		exit(1);
	}
	if((Cripto = fopen("Ajuda_02.txt", "w")) == NULL)
	{
		printf("Errou de novo");
		exit(1);
	}
	do
	{
		Texto = getc(Arquivo);
		if(Texto != EOF)
		{
			putc(Texto + 5, Cripto);
		}
	}
	while(Texto != EOF);
	printf("Deu Certo.");
	return 0;
} // 

void Descriptografa()
{
	char Texto, Printado[101];
	FILE *Cripto, *Descripto;
	if((Cripto = fopen("Ajuda_02.txt", "r")) == NULL)
	{
		printf("Ops... Algo Deu Errado");
		exit(1);
	}
	if((Descripto = fopen("Ajuda_03.txt", "w")) == NULL)
	{
		printf("Ops... Algo Deu Errado");
		exit(1);
	}
	do
	{
		Texto = getc(Cripto);
		if(Texto != EOF)
		{
			putc(Texto - 5, Descripto);
		}
	}
	while(Texto != EOF);
	fclose(Cripto);
	fclose(Descripto);
	if((Descripto = fopen("Ajuda_03.txt", "rt")) == NULL)
	{
		printf("Ops... Algo Deu Errado");
		exit(1);	
	}
	while(fgets(Printado, 100, Descripto) != NULL)
	{
		printf("%s", Printado);
	}
	fclose(Descripto);
} // descriptografa um arquivo

typedef struct
{
	char Nome[100], Sexo[2];
	int ID;
	int idade;
	int CPF[12];
	int Exclusao;
}RH; // Struct com os dados 


int main ()
{
	int id, Verificacao, Resposta_02, Opcao_01, Opcao_02, Opcao_03, Controle_Menuzinho_01, Controle_Menuzinho_02, Controle_Menuzinho_03;
	char Resposta_01, nome[100], String_Auxiliar[100], Nomes_01[100], Nomes_02[100], Tecla_01, Tecla_02, Tecla_03, Nome_Arquivo[50], Nome_Arquivo_Novo[50], Confirmacao;
	RH Dados;
	FILE *Arquivo, *Arquivo_Novo;
	apresentacao();
	system ("cls");
	Opcao_01 = 1;
	Menu_Principal(Opcao_01);
	do // Seleciona as Teclas para o Op��o
	{
		Tecla_01 = getch();
		if(Tecla_01 <= 0)
		{
			Tecla_01 = getch();
			if(Tecla_01 == Baixo)
			{
				if(Opcao_01 != 10)
				{
					Opcao_01++;
				}
				else
				{
					Opcao_01 = 1;
				}
				Menu_Principal(Opcao_01);
			}
			else if(Tecla_01 == Cima)
			{
				if(Opcao_01 != 1)
				{
					Opcao_01--;
				}
				else
				{
					Opcao_01 = 10;
				}
				Menu_Principal(Opcao_01);
			}
			else if(Tecla_01 == f1)
			{
				system("cls");
				Descriptografa();
				getch();
				Menu_Principal(Opcao_01); // Caso Seja F1, ele abre o Arquivo de Ajuda
			}
		}
		else
		{
			if(Tecla_01 == Enter)
			{
				if(Opcao_01 == 1)
				{
					system("cls");
					type("Por favor, digite o nome do arquivo que deseja manipular, sem extensoes\n(se o arquivo nao existir, um novo sera criado): ");
					fflush(stdin);
					gets(Nome_Arquivo);
					strcat(Nome_Arquivo, ".dat");
					if ((Arquivo = fopen(Nome_Arquivo, "r+b")) == NULL)
					{
						if ((Arquivo = fopen(Nome_Arquivo, "wb")) == NULL)
						{
							printf ("Erro ao abrir o arquivo...\n");
							exit (1);
						}
					}
					fseek (Arquivo, 0, SEEK_END);
					do
					{
						system ("cls");
						fflush (stdin);
						printf ("Nome: ");
						gets (Dados.Nome);
						system ("cls");
						printf ("Sexo (1 letra): ");
						gets (Dados.Sexo);
						system ("cls");
						printf ("Idade: ");
						scanf("%d",&Dados.idade);
						system ("cls");
						printf ("CPF: ");
						scanf("%d",&Dados.CPF);
						system ("cls");
						printf ("ID: ");
						gets (String_Auxiliar); // Regista os dados dos funcionarios
						Dados.ID = atoi(String_Auxiliar);
						fwrite (&Dados, sizeof(Dados), 1, Arquivo);
						printf ("Gostaria de adicionar outro? ");
						do
						{
							Resposta_01 = toupper(getch());
						}
						while (Resposta_01 != 'S' && Resposta_01 != 'N');
					}
					while (Resposta_01 == 'S');
					fclose (Arquivo);
					type("\nPara voltar ao menu, pressione qualquer tecla, menos Enter.");
					getch();
				}
				else if(Opcao_01 == 2)
				{
					Controle_Menuzinho_01 = 0;
					Verificacao = 0;
					system ("cls");
					type("Por favor, digite o nome do arquivo que deseja consultar, sem extensoes\n(o arquivo deve existir): ");
					fflush(stdin);
					gets(Nome_Arquivo);
					strcat(Nome_Arquivo, ".dat");
					if ((Arquivo = fopen (Nome_Arquivo, "rb")) == NULL) // Abre o Arquivo que o usuario quiser 
					{
						printf ("Erro ao abrir o arquivo...\n"); 
						exit (1);
					}
					system("cls");
					Menuzinho_01(Opcao_02);
					do
					{
						Tecla_02 = getch();
						if(Tecla_02 <= 0)
						{
							Tecla_02 = getch();
							if(Tecla_02 == Baixo)
							{
								if(Opcao_02 != 2)
								{
									Opcao_02++;
								}
								else
								{
									Opcao_02 = 1;
								}
								Menuzinho_01(Opcao_02);
							}
							else if(Tecla_02 == Cima)
							{
								if(Opcao_02 != 1)
								{
									Opcao_02--;
								}
								else
								{
									Opcao_02 = 2;
								}
								Menuzinho_01(Opcao_02);
							}
							else if(Tecla_02 == f1)
							{
								system("cls");
								Descriptografa();
								getch();
								Menuzinho_01(Opcao_02);
							}
						}
						else if(Tecla_02 == Enter)
						{
							if(Opcao_02 == 1)
							{
								system("cls");
								fflush (stdin);
								printf ("Digite o nome do funcionario: "); // Altera os dados da Struct
								gets (nome);
								while (fread (&Dados, sizeof(Dados), 1, Arquivo) == 1 && !Verificacao)
								{
									if (strcmp (Dados.Nome, nome) == 0 && !Dados.Exclusao)
									{
										system("cls");
										printf ("Nome: %s", Dados.Nome);
										printf ("\nSexo: %s", Dados.Sexo);
										printf ("\nID: %d", Dados.ID);
										printf ("\nCPF: %d", Dados.CPF);
										printf ("\nCPF: %d", Dados.idade);
										Verificacao = 1;
										printf("\nPressione qualquer tecla para sair.");
										getch ();
									}
								}
								if (!Verificacao)
								{
									system("cls");
									printf ("O funcionario %s nao foi encontrado", nome);
									printf("\nPressione qualquer tecla para sair.");
									getch ();
								}
							}
							else if(Opcao_02 == 2)
							{
								system("cls");
								type ("Digite o ID do funcionario: ");
								scanf ("%d", &id);
								system("cls");
								while (fread (&Dados, sizeof(Dados), 1, Arquivo) == 1 && !Verificacao)
								{
									if (Dados.ID == id && !Dados.Exclusao)
									{
										system("cls");
										printf ("Nome: %s", Dados.Nome);
										printf ("\nSexo: %s", Dados.Sexo);
										printf ("\nID: %d", Dados.ID);
										printf ("\nCPF: %d", Dados.CPF);
										printf ("\nCPF: %d", Dados.idade);
										Verificacao = 1;
										type("\nPressione qualquer tecla para sair.");
										getch ();
									}
								}
								if (!Verificacao)
								{
									system("cls");
									printf ("\tO funcionario com ID %d nao foi encontrado", id);
									printf("\nPressione qualquer tecla para sair.");
									getch ();
								}
							}
							Controle_Menuzinho_01 = 1;
						}
					}
					while(Controle_Menuzinho_01 != 1);
					system ("cls");
					printf("Para voltar ao menu, pressione qualquer tecla, menos Enter.");
					getch();
					fclose (Arquivo);
				}
				else if(Opcao_01 == 3)
				{
					Controle_Menuzinho_02 = 0;
					Verificacao = 0;
					system("cls");
					type("Por favor, digite o nome do arquivo que deseja manipular, sem extensoes\n(o arquivo deve existir): ");
					fflush(stdin);
					gets(Nome_Arquivo);
					strcat(Nome_Arquivo, ".dat");
					if ((Arquivo = fopen (Nome_Arquivo, "r+b")) == NULL)
					{
						printf ("Erro ao abrir o arquivo...\n");
						exit (1);
					}
					system ("cls");
					Menuzinho_01(Opcao_02);
					do
					{
						Tecla_02 = getch();
						if(Tecla_02 <= 0)
						{
							Tecla_02 = getch();
							if(Tecla_02 == Baixo)
							{
								if(Opcao_02 != 2)
								{
									Opcao_02++;
								}
								else
								{
									Opcao_02 = 1;
								}
								Menuzinho_01(Opcao_02);
							}
							else if(Tecla_02 == Cima)
							{
								if(Opcao_02 != 1)
								{
									Opcao_02--;
								}
								else
								{
									Opcao_02 = 2;
								}
								Menuzinho_01(Opcao_02);
							}
							else if(Tecla_02 == f1)
							{
								system("cls");
								Descriptografa();
								getch();
								Menuzinho_01(Opcao_02);
							}
						}
						else if(Tecla_02 == Enter)
						{
							if(Opcao_02 == 1)
							{
								system("cls");
								fflush (stdin);
								printf ("Digite o nome do funcionario que deseja alterar: "); // Pesquisa por usuario
								gets (nome);
								while (fread(&Dados, sizeof(Dados), 1, Arquivo) == 1 && !Verificacao)
								{
									if (strcmp(Dados.Nome, nome) == 0 && !Dados.Exclusao)
									{
										printf ("\nNome: %s", Dados.Nome);
										printf ("\nSexo: %s", Dados.Sexo);
										printf ("\nID: %d", Dados.ID);
										printf ("\nCPF: %d", Dados.CPF);
										printf ("\nCPF: %d", Dados.idade);
										printf("\n\nPressione qualquer tecla para prosseguir.");
										getch();
										system("cls");
										fflush (stdin);
										printf ("Nome alterado: ");
										gets (Dados.Nome);
										printf ("\nSexo alterado: ");
										gets (Dados.Sexo);
										printf ("\nIdade alterada: ");
										scanf("%d",&Dados.idade);
										printf ("\nCPF alterado: ");
										scanf("%d",&Dados.CPF);
										printf ("\nID alterado: ");
										gets (String_Auxiliar);
										Dados.ID = atoi (String_Auxiliar);
										fseek (Arquivo, -sizeof(Dados), SEEK_CUR);
										fwrite (&Dados, sizeof(Dados), 1, Arquivo);
										fflush (stdin);
										Verificacao = 1;
										system ("cls");
										printf ("Dados alterados com sucesso!\n");
										printf("Pressione qualquer tecla para sair.");
									}
								}
								if (!Verificacao)
								{
									system("cls");
									printf ("O funcionario %s nao foi encontrado\n", nome);
									printf("Pressione qualquer tecla para sair.");
									getch ();
								}
								getch();
							}
							else if(Opcao_02 == 2)
							{
								system("cls");
								printf ("Digite o ID do funcionario que deseja alterar: "); // Pesquisa por ID
								scanf ("%d", &id);
								while (fread(&Dados, sizeof (Dados), 1, Arquivo) == 1 && !Verificacao)
								{
									if (Dados.ID = id && !Dados.Exclusao)
									{
										printf ("\nNome: %s", Dados.Nome);
										printf ("\nSexo: %s", Dados.Sexo);
										printf ("\nID: %d", Dados.ID);
										printf ("\nCPF: %d", Dados.CPF);
										printf ("\nIdade: %d", Dados.idade);
										printf("\n\nPressione qualquer tecla para prosseguir.");
										getch();
										system("cls");
										fflush (stdin);
										printf ("Nome alterado: ");
										gets (Dados.Nome);
										printf ("\nSexo alterado: ");
										gets (Dados.Sexo);
										printf ("\nIdade alterada: ");
										scanf("%d",&Dados.idade);
										printf ("\nCPF alterado: ");
										scanf("%d",&Dados.CPF);
										printf ("\nID alterado: ");
										gets (String_Auxiliar); // Altera Os dados
										Dados.ID = atoi (String_Auxiliar);
										fseek (Arquivo, -sizeof(Dados), SEEK_CUR);
										fwrite (&Dados, sizeof(Dados), 1, Arquivo);
										fflush (stdin);
										Verificacao = 1;
										system ("cls");
										printf ("Dados alterados com sucesso!\n");
										printf("Pressione qualquer tecla para sair.");
										getch();
									}
								}
								if (!Verificacao)
								{
									system("cls");
									printf ("O funcionario %s nao foi encontrado\n", nome);
									printf("Pressione qualquer tecla para sair.");
									getch ();
								}
								getch();
							}
							Controle_Menuzinho_02 = 1;
						}
					}
					while(Controle_Menuzinho_02 != 1);
					fclose(Arquivo);
					system("cls");
					printf("Para voltar ao menu, pressione qualquer tecla, menos Enter.");
					getch();
				}	
				else if(Opcao_01 == 4)
				{
					Controle_Menuzinho_02 = 0;
					Controle_Menuzinho_03 = 0;
					system("cls");
					printf("Por favor, digite o nome do arquivo que deseja consultar, sem extensoes\n(o arquivo deve existir): ");
					fflush(stdin);
					gets(Nome_Arquivo);
					strcpy(Nome_Arquivo_Novo, Nome_Arquivo); // Consulta pelo nome do Arquivo
					strcat(Nome_Arquivo, ".dat");
					if ((Arquivo = fopen (Nome_Arquivo, "rb")) == NULL)
					{
						printf ("Erro ao abrir o arquivo...\n");
						exit (1);
					}
					strcat(Nome_Arquivo_Novo, "_Novo.dat");
					if((Arquivo_Novo = fopen(Nome_Arquivo_Novo, "r+b")) == NULL)
					{
						if((Arquivo_Novo = fopen(Nome_Arquivo_Novo, "wb")) == NULL)
						{
							printf("Erro ao abrir o arquivo...\n");
							exit(1);
						}
					}
					system("cls");
					Menuzinho_01(Opcao_02);
					do
					{
						Tecla_02 = getch();
						if(Tecla_02 <= 0)
						{
							Tecla_02 = getch();
							if(Tecla_02 == Baixo)
							{
								if(Opcao_02 != 2)
								{
									Opcao_02++;
								}
								else
								{
									Opcao_02 = 1;
								}
								Menuzinho_01(Opcao_02);
							}
							else if(Tecla_02 == Cima)
							{
								if(Opcao_02 != 1)
								{
									Opcao_02--;
								}
								else
								{
									Opcao_02 = 2;
								}
								Menuzinho_01(Opcao_02);
							}
							else if(Tecla_02 == f1)
							{
								system("cls");
								Descriptografa();
								getch();
								Menuzinho_01(Opcao_02);
							}
						}
						else if(Tecla_02 == Enter)
						{
							if(Opcao_02 == 1)
							{
								system("cls");
								Menuzinho_02(Opcao_03);
								do
								{
									Tecla_03 = getch();
									if(Tecla_03 <= 0)
									{
										Tecla_03 = getch();
										if(Tecla_03 == Baixo)
										{
											if(Opcao_03 != 2)
											{
												Opcao_03++;
											}
											else
											{
												Opcao_03 = 1;
											}
											Menuzinho_02(Opcao_03);
										}
										else if(Tecla_03 == Cima)
										{
											if(Opcao_03 != 1)
											{
												Opcao_03--;
											}
											else
											{
												Opcao_03 = 2;
											}
											Menuzinho_02(Opcao_03);
										}
										else if(Tecla_03 == f1)
										{
											system("cls");
											Descriptografa();
											getch();
											Menuzinho_02(Opcao_03);
										}
									}
									else if(Tecla_03 == Enter)
									{
										if(Opcao_03 == 1)
										{
											system("cls");
											printf("Digite o nome do funcionario a ser demitido: ");
											fflush(stdin);
											gets(nome);
											printf("Tem certeza que quer demitir este funcionario? (S/N)\nResposta: ");
											do
											{
												Confirmacao = toupper(getch());
											}
											while(Confirmacao != 'S' && Confirmacao != 'N');
											if(Confirmacao == 'S') // Deleta e confirma os Dados
											{
												while(!feof(Arquivo))
												{
										        	fread(&Dados, sizeof(Dados), 1, Arquivo);
										        	if(strcmp(nome, Dados.Nome))
													{
										        	    fwrite(&Dados, sizeof(Dados), 1, Arquivo_Novo);
										        	}
										    	}	
											    fclose(Arquivo_Novo);
											    fclose(Arquivo);
											    remove(Nome_Arquivo);
											    rename(Nome_Arquivo_Novo, Nome_Arquivo);
											}
											else
											{
												printf("Funcionario %s nao foi demitido\n", nome);
												getch();
											}
										}
										else if(Opcao_03 == 2)
										{
											if((Arquivo = fopen("RH.dat", "r+b")) == NULL)
											{
												printf ("Erro ao abrir o arquivo...\n");
												exit (1);
											}
											system("cls");
											printf("Digite o nome do funcionario a ser demitido: ");
											fflush(stdin);
											gets(nome);
											printf("Tem certeza que quer demitir este funcionario? (S/N)\nResposta: ");
											do
											{
												Confirmacao = toupper(getch());
											}
											while(Confirmacao != 'S' && Confirmacao != 'N');
											if(Confirmacao == 'S')
											{
												while(fread(&Dados, sizeof(Dados), 1, Arquivo) == 1 && !Verificacao)
												{
													if(!Dados.Exclusao && strcmp(Dados.Nome, nome) == 0)
													{
														Dados.Exclusao = 1;
														fseek (Arquivo, -sizeof(Dados), SEEK_CUR);
											    		fwrite(&Dados, sizeof(Dados), 1, Arquivo);
											    		fflush(Arquivo);
											    		printf("Funcionario %s demitido",nome);
													}
												}
											}
											else
											{
												printf("Funcionario %s nao foi demitido\n", nome);
												getch();
											}
										}
										Controle_Menuzinho_03 = 1;
									}
								}
								while(Controle_Menuzinho_03 != 1);
							}
							else if(Opcao_02 == 2)
							{
								system("cls");
								Menuzinho_02(Opcao_03);
								do
								{
									Tecla_03 = getch();
									if(Tecla_03 <= 0)
									{
										Tecla_03 = getch();
										if(Tecla_03 == Baixo)
										{
											if(Opcao_03 != 2)
											{
												Opcao_03++;
											}
											else
											{
												Opcao_03 = 1;
											}
											Menuzinho_02(Opcao_03);
										}
										else if(Tecla_03 == Cima)
										{
											if(Opcao_03 != 1)
											{
												Opcao_03--;
											}
											else
											{
												Opcao_03 = 2;
											}
											Menuzinho_02(Opcao_03);
										}
										else if(Tecla_03 == f1)
										{
											system("cls");
											Descriptografa();
											getch();
											Menuzinho_02(Opcao_03);
										}
									}
									else if(Tecla_03 == Enter)
									{
										if(Opcao_03 == 1)
										{
											system("cls");
											printf("Digite o ID do funcionario a ser demitido: "); // Exclui Dados Pelo ID
											scanf("%d", &id);
											if(Confirmacao == 'S')
											{
												while(!feof(Arquivo))
												{
										        	fread(&Dados, sizeof(Dados), 1, Arquivo);
										        	if(Dados.ID != id)
													{
										        	    fwrite(&Dados, sizeof(Dados), 1, Arquivo_Novo);
										        	}
										    	}	
											    fclose(Arquivo_Novo);
											    fclose(Arquivo);
											    remove(Nome_Arquivo);
											    rename(Nome_Arquivo_Novo, Nome_Arquivo);
											}
											else
											{
												printf("Funcionario %s nao foi demitido\n", nome);
												getch();
											}
										}
										else if(Opcao_03 == 2)
										{
											if((Arquivo = fopen("RH.dat", "r+b")) == NULL)
											{
												printf ("Erro ao abrir o arquivo...\n");
												exit (1);
											}
											system("cls");
											printf("Digite o ID do funcionario a ser demitido: ");
											scanf("%d", &id);
											printf("Tem certeza que quer demitir este funcionario? (S/N)\nResposta: ");
											do
											{
												Confirmacao = toupper(getch());
											}
											while(Confirmacao != 'S' && Confirmacao != 'N');
											if(Confirmacao == 'S')
											{
												while(fread(&Dados, sizeof(Dados), 1, Arquivo) == 1 && !Verificacao)
												{
													if(!Dados.Exclusao && Dados.ID == id)
													{
														Dados.Exclusao = 1;
														fseek (Arquivo, -sizeof(Dados), SEEK_CUR);
											    		fwrite(&Dados, sizeof(Dados), 1, Arquivo);
											    		fflush(Arquivo);
											    		printf("Funcionario %s demitido",nome);
													}
												}
											}
											else
											{
												printf("Funcionario %s nao foi demitido\n", nome);
												getch();
											}
										}
										Controle_Menuzinho_03 = 1;
									}
								}
								while(Controle_Menuzinho_03 != 1);
							}
							Controle_Menuzinho_02 = 1;
						}
					}
					while(Controle_Menuzinho_02 != 1);
					system ("cls");
					printf("Para voltar ao menu, pressione qualquer tecla, menos Enter.");
					getch();
				}
				else if(Opcao_01 == 5)	
				{
					type("Voce podera alterar a data do seu proprio sistema\n");
					system("date");
					printf("Voce alterou a data do seu sistema com sucesso! \n\n"); 
					printf("Para voltar a data anterior, reinsira essa data no Sistema manualmente, ");
					printf("Ou escolha a opcao 4 novamente\n\n");
					Sleep(1000);
					system("cls"); // Altera a data do Sistema
				}
				else if(Opcao_01 == 6)
				{
					type("Voce podera alterar o horario do seu proprio sistema\n");
					system("time");
					printf("Voce alterou o horario do seu sistema com sucesso! \n\n"); 
					printf("Para voltar o horario anteirior, reinsira essa data no Sistema manualmente, ");
					printf("Ou escolha a Opcao_01 4 novamente\n\n");
					Sleep(1000);
					system("cls"); // Altera o Horario do Sistema
				}
				else if(Opcao_01 == 7)
				{
					printf("Nome do arquivo: ");
					fflush(stdin);
					gets(Nomes_01);
					printf("Nome novo: ");
					fflush(stdin);
					gets(Nomes_02);
					renamePasta(Nomes_01, Nomes_02); // Renomeia Pastas
				}
				else if(Opcao_01 == 8)
				{
					printf("Nome do arquivo: ");
					fflush(stdin);
					gets(Nomes_01);
					excluiArq(Nomes_01);
					getch(); // Exlcui O Arquivo
				}
				else if(Opcao_01 == 9)
				{
					printf("Nome da pasta: ");
					fflush(stdin);
					gets(Nomes_01);
					novaPasta(Nomes_01);
					getch(); //  Exclui a Pasta
				}
				else if(Opcao_01 == 10)
				{
					printf("Nome antigo: ");
					fflush(stdin);
					gets(Nomes_01);
					printf("Nome novo: ");
					fflush(stdin);
					gets(Nomes_02);
					renomear(Nomes_01, Nomes_02); // Renomeia o Arquivo
					getch();
				}
			}
			else if(Tecla_01 == Esc)
			{
				system("cls");
				Escreve_Texto(5, 5, "Obrigado pela preferencia!", 15); // Sai do programa
			}
		}
	}
	while (Tecla_01 != Esc);	
	return 0;
}
