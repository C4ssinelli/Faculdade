// Este trabalho realiza operações com matrizes, como deslocamento de linhas e colunas. 
// Além disso, o código identifica matrizes especiais, como matrizes simétricas.
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define linha 20
#define coluna 20
#define maximo 20
//Menu  -------------------------------------------------------------------
void gotoxy (int x,int y) 
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//-------------------------------------------------------------------------
int SetColor (char color) 
{
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}
//-------------------------------------------------------------------------
void escreveTexto (int x,int y,char texto[],int cor)
{
  SetColor (cor);
  gotoxy (y,x);
  printf ("%s",texto);
}
//-------------------------------------------------------------------------
void menu1 (int op)
{
  char vet[][20] = {"Mostrar Matriz", "Trocar Linhas", "Trocar Colunas", "Trocar Diagonais", "Matriz Simetrica", "Quadrado Magico", "Quadrado Latino", "Matriz de Permutacao"};
  int i;
  system ("cls");
  for (i = 0; i < 8; i++)
    escreveTexto (3+i,10,vet[i],3);
  escreveTexto (2+op,10,vet[op-1],15);  
}
void menu2(int op)
{
	char vet[][20] = {"Mostrar Matriz", "Trocar Linhas", "Trocar Colunas"};
	int i;
	system ("cls");
	for (i = 0; i < 3; i++)
	{
    	escreveTexto (3+i,10,vet[i],3);
    }
	escreveTexto (2+op,10,vet[op-1],15);  
}
//-------------------------------------------------------------------------

//leitura do tamanho da matriz
int LeTam1()
{
	int n;
	printf("Diga quantas linhas a matriz tem: ");
	scanf("%d",&n);
	return n;
}
int LeTam2()
{
	int m;
	printf("Diga quantas colunas a matriz tem: ");
	scanf("%d",&m);
	return m;
}
//leitura da matriz
void LeMat(int n,int k,float m[linha][coluna])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("Informe o elemento %d,%d da matriz: ",i+1,j+1);
			scanf("%f",&m[i][j]);
		}
	}
}
//mostra dos elementos da matriz
void PrintMat(float m[linha][coluna],int n,int k)
{
	int i,j;
	printf("Matriz dada:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("\t%.2f\t",m[i][j]);
		}
		printf("\n");
	}
}
//trocar elementos da linha x pelos da linha y
float Linha(float m[linha][coluna],int n,int k)
{
	int x,y,i,j;
	float aux;
	if(n==1)
	{
		system ("cls");
		printf("Nao eh possivel realizar a operacao.\n");
	}
	else
	{
		printf("Por favor, digite quais linhas deseja trocar: ");
		scanf("%d %d",&x,&y);
		if(x>k || y>k)
		{
			system ("cls");
			printf("Nao eh possivel realizar a operacao.\n");
		}
		for(j=0;j<k;j++)
		{
			aux=m[x-1][j];
			m[x-1][j]=m[y-1][j];
			m[y-1][j]=aux;
		}
	}
}
//trocar elementos da coluna x pelos da coluna y
float Coluna(float m[linha][coluna],int n,int k)
{
	int x,y,i,j;
	float aux;
	if(k==1)
	{
		system("cls");
		printf("Nao eh possivel realizar a operacao.\n");
	}
	printf("Por favor, digite quais colunas deseja trocar: ");
	scanf("%d %d",&x,&y);
	if(x>n || y>n)
		{
			system ("cls");
			printf("Nao eh possivel realizar a operacao.\n");
		}
	for(i=0;i<k;i++)
	{
		aux=m[i][x-1];
		m[i][x-1]=m[i][y-1];
		m[i][y-1]=aux;
	}
}
//trocar elementos da diagonal principal com a diagonal secund�ria
float Diagonal(float m[linha][coluna],int n,int k)
{
	int i,j;
	float dprinc[maximo],dsecund[maximo];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(i==j)
			{
				dprinc[i]=m[i][j];
			}
			if(i+j==n-1)
			{
				dsecund[i]=m[i][j];					
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(i==j)
			{
				m[i][j]=dsecund[i];
			}
			if(i+j==n-1)
			{
				m[i][j]=dprinc[i];					
			}
		}
	}
}
//Matriz Sim�trica
int Sim(float m[linha][coluna],int n,int k)
{
	int i,j,S=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(m[i][j]!=m[j][i])
			{
				S+=1;
			}
		}
	}
	if(S!=0)
	{
		return 0;
	}
	else if(S==0)
	{
		return 1;
	}
}
//Quadrado M�gico.
int QM(float m[linha][coluna],int n,int k)
{
	int i,j,Sl=0;
	float SL=0,SC=0,SDP=0,SDS=0,vL[maximo],vC[maximo];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			SL+=m[i][j];
			if(i==j)
			{
				SDP+=m[i][j];
			}
			if(i+j==n-1)
			{
				SDS+=m[i][j];
			}
		}
		vL[i]=SL;
		SL=0;
	}
	for(j=0;j<k;j++)
	{
		for(i=0;i<n;i++)
		{
			SC+=m[i][j];
		}
		vC[j]=SC;
		SC=0;
	}
	for(i=0,j=0;i<n,j<k;i++,j++)
	{
		if(vL[i]!=vC[j])
		{
			Sl+=1;
		}
	}
	if(SDP!=SDS)
	{
		Sl+=1;
	}
	if(Sl!=0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//Quadrado Latino
int QL(float m[linha][coluna],int n,int h)
{
	int i,j,k,l,SQL=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<h-1;j++)
		{
			if(m[i][j]<1 || m[i][j]>h)
			{
				SQL+=1;
			}
			for(l=j+1;l<h;l++)
			{
				if(m[i][j]==m[i][l])
				{
					SQL+=1;
				}
			}
		}
	}
	for(j=0;j<h;j++)
	{
		for(i=0;i<n-1;i++)
		{
			if(m[i][j]<1 || m[i][j]>n)
			{
				SQL+=1;
			}
			for(k=i+1;k<n;k++)
			{
				if(m[i][j]==m[k][j])
				{
					SQL+=1;
				}
			}
		}
	}
	if(SQL!=0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//Matriz de Permuta��o
int MP(float m[linha][coluna],int n,int k)
{
	int i,j,SL1=0,SPL=0,SL0=0,SPC=0,SC1=0,SC0=0,vSPL[maximo],vSPC[maximo],vSL0[maximo],vSL1[maximo],vSC0[maximo],vSC1[maximo],SFinal=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(m[i][j]!=0 && m[i][j]!=1)
			{
				SPL+=1;
			}
			else if(m[i][j]==0)
			{
				SL0+=1;
			}
			else if(m[i][j]==1)
			{
				SL1+=1;
			}
		}
		vSPL[i]=SPL;
		vSL0[i]=SL0;
		vSL1[i]=SL1;
		SPL=0;
		SL0=0;
		SL1=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(m[j][i]!=0 && m[j][i]!=1)
			{
				SPC+=1;
			}
			else if(m[j][i]==0)
			{
				SC0+=1;
			}
			else if(m[j][i]==1)
			{
				SC1+=1;
			}
		}
		vSPC[i]=SPC;
		vSC0[i]=SC0;
		vSC1[i]=SC1;
		SPC=0;
		SC0=0;
		SC1=0;
	}
	for(i=0;i<n;i++)
	{
		if(vSPC[i]!=0 || vSC0[i]<n-1 || vSC1[i]>1)
		{
			SFinal+=1;
		}
	}
	if(SFinal==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//main
int main ()
{
	int tam1,tam2,lin=1,i,j;
	float m[linha][coluna];
	char opcao=0;
	do
	{
		tam1=LeTam1();
	}
	while(tam1<1 || tam1>linha);
	do
	{
		tam2=LeTam2();
	}
	while(tam2<1 || tam2>coluna);
	if(tam1!=tam2)
	{
		LeMat(tam1,tam2,m);
		do
		{
			menu2(lin);
			opcao=getch();
			if(opcao==cima)
			{
				if(lin==1)
				{
					lin=3;
				}
				else
				{
					lin--;
				}
			}
			else if(opcao==baixo)
			{
				if(lin==3)
				{
					lin=1;
				}
				else
				{
					lin++;
				}
			}
			else if(opcao==enter)
			{
				if(lin==1)
				{
					system("cls");
					PrintMat(m,tam1,tam2);
					printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
					printf("\tPara sair pressione a tecla esc");
					opcao=getch();
				}
				else if(lin==2)
				{
					system("cls");
					Linha(m,tam1,tam2);
					printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
					printf("\tPara sair pressione a tecla esc");
					opcao=getch();
				}
				else if(lin==3)
				{
					system("cls");
					Coluna(m,tam1,tam2);
					printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
					printf("\tPara sair pressione a tecla esc");
					opcao=getch();
				}
			}
			system("cls");
		}
		while(opcao!=esc);
	}
	else
	{
		LeMat(tam1,tam2,m);
		do
		{
			menu1(lin);
			opcao=getch();
			if(opcao==cima)
			{
				if(lin==1)
				{
					lin==8;
				}
				else
				{
					lin--;
				}
			}
			else if(opcao==baixo)
			{
				if(lin==8)
				{
					lin=1;
				}
				else
				{
					lin++;
				}
			}
			if(opcao==enter)
			{
				if(lin==1)
				{
					system("cls");
					PrintMat(m,tam1,tam2);
					printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
					printf("\tPara sair pressione a tecla esc");
					opcao=getch();
				}
				else if(lin==2)
				{
					system("cls");
					Linha(m,tam1,tam2);
					printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
					printf("\tPara sair pressione a tecla esc");
					opcao=getch();
				}
				else if(lin==3)
				{
					system("cls");
					Coluna(m,tam1,tam2);
					printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
					printf("\tPara sair pressione a tecla esc");
					opcao=getch();
				}
				else if(lin==4)
				{
					system("cls");
					Diagonal(m,tam1,tam2);
					printf("\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
					printf("\tPara sair pressione a tecla esc");
					opcao=getch();
				}
				else if(lin==5)
				{
					system("cls");
					Sim(m,tam1,tam2);
					if(Sim(m,tam1,tam2)==1)
					{
						printf("A matriz eh Simetrica.\n");
						printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
						printf("\tPara sair pressione a tecla esc");
						opcao=getch();
					}
					else
					{
						printf("A matriz nao eh Simetrica.\n");
						printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
						printf("\tPara sair pressione a tecla esc");
						opcao=getch();
					}
				}
				else if(lin==6)
				{
					system("cls");
					QM(m,tam1,tam2);
					if(QM(m,tam1,tam2)==1)
					{
						printf("A matriz eh Quadrado Magico.\n");
						printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
						printf("\tPara sair pressione a tecla esc");
						opcao=getch();
					}
					else
					{
						printf("A matriz eh nao Quadrado Magico.\n");
						printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
						printf("\tPara sair pressione a tecla esc");
						opcao=getch();
					}
				}
				else if(lin==7)
				{
					system("cls");
					QL(m,tam1,tam2);
					if(QL(m,tam1,tam2)==1)
					{
						printf("A matriz eh Quadrado Latino.\n");
						printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
						printf("\tPara sair pressione a tecla esc");
						opcao=getch();
					}
					else
					{
						printf("A matriz nao eh Quadrado Latino.\n");
						printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
						printf("\tPara sair pressione a tecla esc");
						opcao=getch();
					}
				}
				else if(lin==8)
				{
					system("cls");
					MP(m,tam1,tam2);
					if(MP(m,tam1,tam2)==1)
					{
						printf("A matriz eh Matriz de Permutacao.\n");
						printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
						printf("\tPara sair pressione a tecla esc");
						opcao=getch();
					}
					else
					{
						printf("A matriz nao eh Matriz de Permutacao.\n");
						printf("\n\n\tPara voltar ao menu, pressione alguma das seguintes telas:\n1. Seta para cima\n2. Seta para baixo\n3. Enter\n");
						printf("\tPara sair pressione a tecla esc");
						opcao=getch();
					}
				}
			}
			system("cls");
		}
		while(opcao!=esc);
	}
	return 0;
}
