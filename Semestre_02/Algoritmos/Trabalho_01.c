// Este trabalho simula o funcionamento de um caixa eletrônico: 
// O código recebe um valor monetário e devolve a quantidade de notas e moedas a serem devolvidas
// o código também preenche talões de cheque

/*Senha 0000*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Leitura da Senha
void Ler_Senha(char Senha[7])
{
	scanf("%s", Senha);
}

//Verificacao da Senha
int Comparacao_de_Senhas(char Senha[7])
{
	char Sh[7];
	strcpy(Sh,"0000");
	if(strcmp(Sh,Senha) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//Ler salario
void Ler_Salario (double *Salario)
{
	scanf("%lf", &*Salario);
}

//Mostrar quantas notas vao ser emitidas pela maquina
void Print_Notas(double Salario)
{
	double A;
	int b,c,d,e,f,g,h,i=10000,j=5000,k=2000,l=1000,m=500,n=200,o=100,p=50,q=25,r=10,s=5,t=1,B,C,D,E,F;
	A=Salario*100;
	b=(int)A%i;
	c=(int)b%j;
	d=(int)c%k;
	e=(int)d%l;
	f=(int)e%m;
	g=(int)f%n;
	h=(int)g%o;
	B=(int)h%p;
	C=(int)B%q;
	D=(int)C%r;
	E=(int)D%s;
	F=(int)E%t;
	printf("NOTAS:\n%d nota(s) de B$ 100.00\n%d nota(s) de B$ 50.00\n%d nota(s) de B$ 20.00\n%d nota(s) de B$ 10.00\n%d nota(s) de B$ 5.00\n%d nota(s) de B$ 2.00\n",(int)A/i,b/j,c/k,d/l,e/m,f/n);
	printf("MOEDAS:\n%d moeda(s) de B$ 1.00\n%d moeda(s) de B$ 0.50\n%d moeda(s) de B$ 0.25\n%d moeda(s) de B$ 0.10\n%d moeda(s) de B$ 0.05\n%d moeda(s) de B$ 0.01\n",g/o,h/p,B/q,C/r,D/s,E/t);
}

//Ler o cheque
void Ler_Cheque (char Cheque_Bits[], char Cheque_Centi[])
{
	printf("Por favor, digite a parte dos bits: ");
	scanf ("%s", Cheque_Bits);
	if (strlen (Cheque_Bits) >= 13)
	{
		do
		{
			system ("cls");
			printf("O valor excede a capacidade do banco, por favor, digite um valor menor: ");
			scanf ("%s", Cheque_Bits);
		}
		while (strlen (Cheque_Bits) >= 13);
	}
	else if (strlen (Cheque_Bits) == 1 && Cheque_Bits[0] == '0')
	{
		do
		{
			printf("Valor invalido, por favor digite um valor valido: ");
			scanf ("%s", Cheque_Bits);
		}
		while (strlen (Cheque_Bits) == 1 && Cheque_Bits[0] == '0');
	}
	system ("cls");
	printf("Por favor, digite a parte dos centibits: ");
	scanf ("%s", Cheque_Centi);
	if (strlen (Cheque_Centi) >= 3)
	{
		do
		{
			system ("cls");
			printf("O valor excede a capacidade do banco, por favor, digite um valor menor: ");
			scanf ("%s", Cheque_Centi);
		}
		while (strlen (Cheque_Centi) >= 3);
	}
	else if (strlen (Cheque_Centi) == 1 && Cheque_Centi[0] == '0')
	{
		do
		{
			printf("Valor invalido, por favor digite um valor valido: ");
			scanf ("%s", Cheque_Centi);
		}
		while (strlen (Cheque_Centi) == 1 && Cheque_Centi[0] == '0');
	}
	strrev (Cheque_Bits);
	strrev (Cheque_Centi);
}

//Numero por extenso, primeira unidade centibits
void Extenso_CP1 (char numero[], char extenso[], int i, int contagem)
{
		if (numero[i] == '1')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "um");
			}
		}
		else
		{
			strcat (extenso, "Um");
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "dois");
			}
		}
		else
		{
			strcat (extenso, "Dois");
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "tres");
			}
		}
		else
		{
			strcat (extenso, "Tres");
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "quatro");
			}
		}
		else
		{
			strcat (extenso, "Quatro");
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "cinco");
			}
		}
		else
		{
			strcat (extenso, "Cinco");
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "seis");
			}
		}
		else
		{
			strcat (extenso, "Seis");
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "sete");
			}
		}
		else
		{
			strcat (extenso, "Sete");
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "oito");
			}
		}
		else
		{
			strcat (extenso, "Oito");
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "nove");
			}
		}
		else
		{
			strcat (extenso, "Nove");
		}
	}
}

//numero por extenso, segunda unidade
void Extenso_CP2 (char numero[], char extenso[], int contagem)
{
	if (numero[contagem] == '1')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "dez");
		}
		else if (numero[contagem - 1] == '1')
		{
			strcat (extenso, "onze");
		}
		else if (numero[contagem - 1] == '2')
		{
			strcat (extenso, "doze");
		}
		else if (numero[contagem - 1] == '3')
		{
			strcat (extenso, "treze");
		}
		else if (numero[contagem - 1] == '4')
		{
			strcat (extenso, "catorze");
		}
		else if (numero[contagem - 1] == '5')
		{
			strcat (extenso, "quinze");
		}
		else if (numero[contagem - 1] == '6')
		{
			strcat (extenso, "dezesseis");
		}
		else if (numero[contagem - 1] == '7')
		{
			strcat (extenso, "dezessete");
		}
		else if (numero[contagem - 1] == '8')
		{
			strcat (extenso, "dezoito");
		}
		else if (numero[contagem - 1] == '9')
		{
			strcat (extenso, "dezenove");
		}
	}
	else if (numero[contagem] == '2')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "vinte");
		}
		else
		{
			strcat (extenso, "vinte e ");
		}
	}
	else if (numero[contagem] == '3')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "trinta");
		}
		else
		{
			strcat (extenso, "trinta e ");
		}
	}
	else if (numero[contagem] == '4')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "quarenta");
		}
		else
		{
			strcat (extenso, "quarenta e ");
		}
	}
	else if (numero[contagem] == '5')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "cinquenta");
		}
		else
		{
			strcat (extenso, "cinquenta e ");
		}
	}
	else if (numero[contagem] == '6')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "sessenta");
		}
		else
		{
			strcat (extenso, "sessenta e ");
		}
	}
	else if (numero[contagem] == '7')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "setenta");
		}
		else
		{
			strcat (extenso, "setenta e ");
		}
	}
	else if (numero[contagem] == '8')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "oitenta");
		}
		else
		{
			strcat (extenso, "oitenta e ");
		}
	}
	else if (numero[contagem] == '9')
	{
		if (numero[contagem - 1] == '0')
		{
			strcat (extenso, "noventa");
		}
		else
		{
			strcat (extenso, "noventa e ");
		}
	}
}

//Numero por extenso, primeira unidade
void Extenso_P1 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "um");
			}
		}
		else
		{
			strcat (extenso, "Um");
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "dois");
			}
		}
		else
		{
			strcat (extenso, "Dois");
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "tres");
			}
		}
		else
		{
			strcat (extenso, "Tres");
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "quatro");
			}
		}
		else
		{
			strcat (extenso, "Quatro");
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "cinco");
			}
		}
		else
		{
			strcat (extenso, "Cinco");
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "seis");
			}
		}
		else
		{
			strcat (extenso, "Seis");
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "sete");
			}
		}
		else
		{
			strcat (extenso, "Sete");
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "oito");
			}
		}
		else
		{
			strcat (extenso, "Oito");
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 2)
		{
			if (numero[i + 1] == '1')
			{
				strcat (extenso, "");
			}
			else
			{
				strcat (extenso, "nove");
			}
		}
		else
		{
			strcat (extenso, "Nove");
		}
	}
}

//Numero por extenso, segunda unidade
void Extenso_P2 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "dez");
			}
			else if (numero[i - 1] == '1')
			{
				strcat (extenso, "onze");
			}
			else if (numero[i - 1] == '2')
			{
				strcat (extenso, "doze");
			}
			else if (numero[i - 1] == '3')
			{
				strcat (extenso, "treze");
			}
			else if (numero[i - 1] == '4')
			{
				strcat (extenso, "catorze");
			}
			else if (numero[i - 1] == '5')
			{
				strcat (extenso, "quinze");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "dezesseis");
			}
			else if (numero[i - 1] == '7')
			{
				strcat (extenso, "dezessete");
			}
			else if (numero[i - 1] == '8')
			{
				strcat (extenso, "dezoito");
			}
			else if (numero[i - 1] == '9')
			{
				strcat (extenso, "dezenove");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Dez");
			}
			else if (numero[i - 1] == '1')
			{
				strcat (extenso, "Onze");
			}
			else if (numero[i - 1] == '2')
			{
				strcat (extenso, "Doze");
			}
			else if (numero[i - 1] == '3')
			{
				strcat (extenso, "Treze");
			}
			else if (numero[i - 1] == '4')
			{
				strcat (extenso, "Catorze");
			}
			else if (numero[i - 1] == '5')
			{
				strcat (extenso, "Quinze");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "Dezesseis");
			}
			else if (numero[i - 1] == '7')
			{
				strcat (extenso, "Dezessete");
			}
			else if (numero[i - 1] == '8')
			{
				strcat (extenso, "Dezoito");
			}
			else if (numero[i - 1] == '9')
			{
				strcat (extenso, "Dezenove");
			}
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "vinte");
			}
			else
			{
				strcat (extenso, "vinte e ");
			}	
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Vinte");
			}
			else
			{
				strcat (extenso, "Vinte e ");
			}
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "trinta");
			}
			else
			{
				strcat (extenso, "trinta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Trinta");
			}
			else
			{
				strcat (extenso, "Trinta e ");
			}
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "quarenta");
			}
			else
			{
				strcat (extenso, "quarenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Quarenta");
			}
			else
			{
				strcat (extenso, "Quarenta e ");
			}
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "cinquenta");
			}
			else
			{
				strcat (extenso, "cinquenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Cinquenta");
			}
			else
			{
				strcat (extenso, "Cinquenta e ");
			}
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "sessenta");
			}
			else
			{
				strcat (extenso, "sessenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Sessenta");
			}
			else
			{
				strcat (extenso, "Sessenta e ");
			}
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "setenta");
			}
			else
			{
				strcat (extenso, "setenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Setenta");
			}
			else
			{
				strcat (extenso, "Setenta e ");
			}
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "oitenta");
			}
			else
			{
				strcat (extenso, "oitenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Oitenta");
			}
			else
			{
				strcat (extenso, "Oitenta e ");
			}
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 3)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "noventa");
			}
			else
			{
				strcat (extenso, "noventa e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Noventa");
			}
			else
			{
				strcat (extenso, "Noventa e ");
			}
		}
	}
}

//numero por extenso, terceira unidade
void Extenso_P3 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (numero[i - 1] == '0' && numero[i - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "cem");
			}
			else
			{
				strcat (extenso, "Cem");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "cento e ");
			}
			else
			{
				strcat (extenso, "Cento e ");
			}
		}
	}
	else if (numero[i] == '2')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "duzentos");
			}
			else
			{
				strcat (extenso, "Duzentos");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "duzentos e ");
			}
			else
			{
				strcat (extenso, "Duzentos e ");
			}
		}
	}
	else if (numero[i] == '3')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "trezentos");
			}
			else
			{
				strcat (extenso, "Trezentos");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "trezentos e ");
			}
			else
			{
				strcat (extenso, "Trezentos e ");
			}
		}
	}
	else if (numero[i] == '4')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "quatrocentos");
			}
			else
			{
				strcat (extenso, "Quatrocentos");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "quatrocentos e ");
			}
			else
			{
				strcat (extenso, "Quatrocentos e ");
			}
		}
	}
	else if (numero[i] == '5')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "quinhentos");
			}
			else
			{
				strcat (extenso, "Quinhentos");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "quinhentos e ");
			}
			else
			{
				strcat (extenso, "Quinhentos e ");
			}
		}
	}
	else if (numero[i] == '6')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "seiscentos");
			}
			else
			{
				strcat (extenso, "Seiscentos");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "seiscentos e ");
			}
			else
			{
				strcat (extenso, "Seiscentos e ");
			}
		}
	}
	else if (numero[i] == '7')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "setecentos");
			}
			else
			{
				strcat (extenso, "Setecentos");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "setecentos e ");
			}
			else
			{
				strcat (extenso, "Setecentos e ");
			}
		}
	}
	else if (numero[i] == '8')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "oitocentos");
			}
			else
			{
				strcat (extenso, "Oitocentos");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "oitocentos e ");
			}
			else
			{
				strcat (extenso, "Oitocentos e ");
			}
		}
	}
	else if (numero[i] == '9')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 4)
			{
				strcat (extenso, "novecentos");
			}
			else
			{
				strcat (extenso, "Novecentos");
			}
		}
		else
		{
			if (contagem >= 4)
			{
				strcat (extenso, "novecentos e ");
			}
			else
			{
				strcat (extenso, "Novecentos e ");
			}
		}
	}
}

//Numero por Extenso, unidade de milhar
void Extenso_P4 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "mil ");
		}
		else
		{
			strcat (extenso, "Mil ");
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "dois mil ");
		}
		else
		{
			strcat (extenso, "Dois mil ");
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "tres mil ");
		}
		else
		{
			strcat (extenso, "Tres mil ");
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "quatro mil ");
		}
		else
		{
			strcat (extenso, "Quatro mil ");
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "cinco mil ");
		}
		else
		{
			strcat (extenso, "Cinco mil ");
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "seis mil ");
		}
		else
		{
			strcat (extenso, "Seis mil ");
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "sete mil ");
		}
		else
		{
			strcat (extenso, "Sete mil ");
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "oito mil ");
		}
		else
		{
			strcat (extenso, "Oito mil ");
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 5)
		{
			strcat (extenso, "nove mil ");
		}
		else
		{
			strcat (extenso, "Nove mil ");
		}
	}
}

//Numero por Extenso, dezena de milhar
void Extenso_P5 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "dez mil ");
			}
			else if (numero[i - 1] == '1')
			{
				strcat (extenso, "onze mil ");
			}
			else if (numero[i - 1] == '2')
			{
				strcat (extenso, "doze mil ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "treze mil ");
			}
			else if (numero[i - 1] == '4')
			{
				strcat (extenso, "catorze mil ");
			}
			else if (numero[i - 1] == '5')
			{
				strcat (extenso, "quinze mil ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "dezesseis mil ");
			}
			else if (numero[i - 1] == '7')
			{
				strcat (extenso, "dezessete mil ");
			}
			else if (numero[i - 1] == '8')
			{
				strcat (extenso, "dezoito mil ");
			}
			else if (numero[i - 1] == '9')
			{
				strcat (extenso, "dezenove mil ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Dez mil ");
			}
			else if (numero[i - 1] == '1')
			{
				strcat (extenso, "Onze mil ");
			}
			else if (numero[i - 1] == '2')
			{
				strcat (extenso, "Doze mil ");
			}
			else if (numero[i - 1] == '3')
			{
				strcat (extenso, "Treze mil ");
			}
			else if (numero[i - 1] == '4')
			{
				strcat (extenso, "Catorze mil ");
			}
			else if (numero[i - 1] == '5')
			{
				strcat (extenso, "Quinze mil ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "Dezesseis mil ");
			}
			else if (numero[i - 1] == '7')
			{
				strcat (extenso, "Dezessete mil ");
			}
			else if (numero[i - 1] == '8')
			{
				strcat (extenso, "Dezoito mil ");
			}
			else if (numero[i - 1] == '9')
			{
				strcat (extenso, "Dezenove mil ");
			}
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "vinte mil ");
			}
			else
			{
				strcat (extenso, "vinte e ");
			}	
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Vinte mil ");
			}
			else
			{
				strcat (extenso, "Vinte e ");
			}
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "trinta mil ");
			}
			else
			{
				strcat (extenso, "trinta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Trinta mil ");
			}
			else
			{
				strcat (extenso, "Trinta e ");
			}
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "quarenta mil ");
			}
			else
			{
				strcat (extenso, "quarenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Quarenta mil ");
			}
			else
			{
				strcat (extenso, "Quarenta e ");
			}
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "cinquenta mil ");
			}
			else
			{
				strcat (extenso, "cinquenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Cinquenta mil ");
			}
			else
			{
				strcat (extenso, "Cinquenta e ");
			}
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "sessenta mil ");
			}
			else
			{
				strcat (extenso, "sessenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Sessenta mil ");
			}
			else
			{
				strcat (extenso, "Sessenta e ");
			}
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "setenta mil ");
			}
			else
			{
				strcat (extenso, "setenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Setenta mil ");
			}
			else
			{
				strcat (extenso, "Setenta e ");
			}
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "oitenta mil ");
			}
			else
			{
				strcat (extenso, "oitenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Oitenta mil ");
			}
			else
			{
				strcat (extenso, "Oitenta e ");
			}
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 6)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "noventa mil ");
			}
			else
			{
				strcat (extenso, "noventa e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Noventa mil ");
			}
			else
			{
				strcat (extenso, "Noventa e ");
			}
		}
	}
}

//Numero por Extenso, centena de milhar
void Extenso_P6 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (numero[i - 1] == '0' && numero[i - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "cem mil");
			}
			else
			{
				strcat (extenso, "Cem mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "cento e ");
			}
			else
			{
				strcat (extenso, "Cento e ");
			}
		}
	}
	else if (numero[i] == '2')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "duzentos mil");
			}
			else
			{
				strcat (extenso, "Duzentos mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "duzentos e ");
			}
			else
			{
				strcat (extenso, "Duzentos e ");
			}
		}
	}
	else if (numero[i] == '3')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "trezentos mil");
			}
			else
			{
				strcat (extenso, "Trezentos mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "trezentos e ");
			}
			else
			{
				strcat (extenso, "Trezentos e ");
			}
		}
	}
	else if (numero[i] == '4')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "quatrocentos mil");
			}
			else
			{
				strcat (extenso, "Quatrocentos mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "quatrocentos e ");
			}
			else
			{
				strcat (extenso, "Quatrocentos e ");
			}
		}
	}
	else if (numero[i] == '5')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "quinhentos mil");
			}
			else
			{
				strcat (extenso, "Quinhentos mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "quinhentos e ");
			}
			else
			{
				strcat (extenso, "Quinhentos e ");
			}
		}
	}
	else if (numero[i] == '6')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "seiscentos mil");
			}
			else
			{
				strcat (extenso, "Seiscentos mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "seiscentos e ");
			}
			else
			{
				strcat (extenso, "Seiscentos e ");
			}
		}
	}
	else if (numero[i] == '7')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "setecentos mil");
			}
			else
			{
				strcat (extenso, "Setecentos mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "setecentos e ");
			}
			else
			{
				strcat (extenso, "Setecentos e ");
			}
		}
	}
	else if (numero[i] == '8')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "oitocentos mil");
			}
			else
			{
				strcat (extenso, "Oitocentos mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "oitocentos e ");
			}
			else
			{
				strcat (extenso, "Oitocentos e ");
			}
		}
	}
	else if (numero[i] == '9')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 7)
			{
				strcat (extenso, "novecentos mil");
			}
			else
			{
				strcat (extenso, "Novecentos mil");
			}
		}
		else
		{
			if (contagem >= 7)
			{
				strcat (extenso, "novecentos e ");
			}
			else
			{
				strcat (extenso, "Novecentos e ");
			}
		}
	}
}

//Numero por extenso, unidade de milhao
void Extenso_P7 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "um milhoes ");
		}
		else
		{
			strcat (extenso, "Um milhao ");
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "dois milhoes ");
		}
		else
		{
			strcat (extenso, "Dois milhoes ");
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "tres milhoes ");
		}
		else
		{
			strcat (extenso, "Tres milhoes ");
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "quatro milhoes ");
		}
		else
		{
			strcat (extenso, "Quatro milhoes ");
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "cinco milhoes ");
		}
		else
		{
			strcat (extenso, "Cinco milhoes ");
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "seis milhoes ");
		}
		else
		{
			strcat (extenso, "Seis milhoes ");
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "sete milhoes ");
		}
		else
		{
			strcat (extenso, "Sete milhoes ");
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "oito milhoes ");
		}
		else
		{
			strcat (extenso, "Oito milhoes ");
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 8)
		{
			strcat (extenso, "nove milhoes ");
		}
		else
		{
			strcat (extenso, "Nove milhoes ");
		}
	}
}

//Numero por extenso, dezena de milhao
void Extenso_P8 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "dez milhoes ");
			}
			else if (numero[i - 1] == '1')
			{
				strcat (extenso, "onze milhoes ");
			}
			else if (numero[i - 1] == '2')
			{
				strcat (extenso, "doze milhoes ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "treze milhoes ");
			}
			else if (numero[i - 1] == '4')
			{
				strcat (extenso, "catorze milhoes ");
			}
			else if (numero[i - 1] == '5')
			{
				strcat (extenso, "quinze milhoes ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "dezesseis milhoes ");
			}
			else if (numero[i - 1] == '7')
			{
				strcat (extenso, "dezessete milhoes ");
			}
			else if (numero[i - 1] == '8')
			{
				strcat (extenso, "dezoito milhoes ");
			}
			else if (numero[i - 1] == '9')
			{
				strcat (extenso, "dezenove milhoes ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Dez milhoes ");
			}
			else if (numero[i - 1] == '1')
			{
				strcat (extenso, "Onze milhoes ");
			}
			else if (numero[i - 1] == '2')
			{
				strcat (extenso, "Doze milhoes ");
			}
			else if (numero[i - 1] == '3')
			{
				strcat (extenso, "Treze milhoes ");
			}
			else if (numero[i - 1] == '4')
			{
				strcat (extenso, "Catorze milhoes ");
			}
			else if (numero[i - 1] == '5')
			{
				strcat (extenso, "Quinze milhoes ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "Dezesseis milhoes ");
			}
			else if (numero[i - 1] == '7')
			{
				strcat (extenso, "Dezessete milhoes ");
			}
			else if (numero[i - 1] == '8')
			{
				strcat (extenso, "Dezoito milhoes ");
			}
			else if (numero[i - 1] == '9')
			{
				strcat (extenso, "Dezenove milhoes ");
			}
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "vinte milhoes ");
			}
			else
			{
				strcat (extenso, "vinte e ");
			}	
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Vinte milhoes ");
			}
			else
			{
				strcat (extenso, "Vinte e ");
			}
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "trinta milhoes ");
			}
			else
			{
				strcat (extenso, "trinta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Trinta milhoes ");
			}
			else
			{
				strcat (extenso, "Trinta e ");
			}
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "quarenta milhoes ");
			}
			else
			{
				strcat (extenso, "quarenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Quarenta milhoes ");
			}
			else
			{
				strcat (extenso, "Quarenta e ");
			}
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "cinquenta milhoes ");
			}
			else
			{
				strcat (extenso, "cinquenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Cinquenta milhoes ");
			}
			else
			{
				strcat (extenso, "Cinquenta e ");
			}
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "sessenta milhoes ");
			}
			else
			{
				strcat (extenso, "sessenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Sessenta milhoes ");
			}
			else
			{
				strcat (extenso, "Sessenta e ");
			}
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "setenta milhoes ");
			}
			else
			{
				strcat (extenso, "setenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Setenta milhoes ");
			}
			else
			{
				strcat (extenso, "Setenta e ");
			}
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "oitenta milhoes ");
			}
			else
			{
				strcat (extenso, "oitenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Oitenta milhoes ");
			}
			else
			{
				strcat (extenso, "Oitenta e ");
			}
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 9)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "noventa milhoes ");
			}
			else
			{
				strcat (extenso, "noventa e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Noventa milhoes ");
			}
			else
			{
				strcat (extenso, "Noventa e ");
			}
		}
	}
}

//Numero por extenso, centena de milhao
void Extenso_P9 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (numero[i - 1] == '0' && numero[i - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "cem milhoes");
			}
			else
			{
				strcat (extenso, "Cem milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "cento e ");
			}
			else
			{
				strcat (extenso, "Cento e ");
			}
		}
	}
	else if (numero[i] == '2')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "duzentos milhoes");
			}
			else
			{
				strcat (extenso, "Duzentos milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "duzentos e ");
			}
			else
			{
				strcat (extenso, "Duzentos e ");
			}
		}
	}
	else if (numero[i] == '3')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "trezentos milhoes");
			}
			else
			{
				strcat (extenso, "Trezentos milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "trezentos e ");
			}
			else
			{
				strcat (extenso, "Trezentos e ");
			}
		}
	}
	else if (numero[i] == '4')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "quatrocentos milhoes");
			}
			else
			{
				strcat (extenso, "Quatrocentos milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "quatrocentos e ");
			}
			else
			{
				strcat (extenso, "Quatrocentos e ");
			}
		}
	}
	else if (numero[i] == '5')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "quinhentos milhoes");
			}
			else
			{
				strcat (extenso, "Quinhentos milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "quinhentos e ");
			}
			else
			{
				strcat (extenso, "Quinhentos e ");
			}
		}
	}
	else if (numero[i] == '6')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "seiscentos milhoes");
			}
			else
			{
				strcat (extenso, "Seiscentos milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "seiscentos e ");
			}
			else
			{
				strcat (extenso, "Seiscentos e ");
			}
		}
	}
	else if (numero[i] == '7')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "setecentos milhoes");
			}
			else
			{
				strcat (extenso, "Setecentos milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "setecentos e ");
			}
			else
			{
				strcat (extenso, "Setecentos e ");
			}
		}
	}
	else if (numero[i] == '8')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "oitocentos milhoes");
			}
			else
			{
				strcat (extenso, "Oitocentos milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "oitocentos e ");
			}
			else
			{
				strcat (extenso, "Oitocentos e ");
			}
		}
	}
	else if (numero[i] == '9')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			if (contagem >= 10)
			{
				strcat (extenso, "novecentos milhoes");
			}
			else
			{
				strcat (extenso, "Novecentos milhoes");
			}
		}
		else
		{
			if (contagem >= 10)
			{
				strcat (extenso, "novecentos e ");
			}
			else
			{
				strcat (extenso, "Novecentos e ");
			}
		}
	}
}

//Numero por extenso, unidade de bilhao
void Extenso_P10 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "um bilhoes ");
		}
		else
		{
			strcat (extenso, "Um bilhao ");
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "dois bilhoes ");
		}
		else
		{
			strcat (extenso, "Dois bilhoes ");
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "tres bilhoes ");
		}
		else
		{
			strcat (extenso, "Tres bilhoes ");
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "quatro bilhoes ");
		}
		else
		{
			strcat (extenso, "Quatro bilhoes ");
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "cinco bilhoes ");
		}
		else
		{
			strcat (extenso, "Cinco bilhoes ");
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "seis bilhoes ");
		}
		else
		{
			strcat (extenso, "Seis bilhoes ");
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "sete bilhoes ");
		}
		else
		{
			strcat (extenso, "Sete bilhoes ");
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "oito bilhoes ");
		}
		else
		{
			strcat (extenso, "Oito bilhoes ");
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 11)
		{
			strcat (extenso, "nove bilhoes ");
		}
		else
		{
			strcat (extenso, "Nove bilhoes ");
		}
	}
}

//Numero por extenso, dezena de bilhao
void Extenso_P11 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "dez bilhoes ");
			}
			else if (numero[i - 1] == '1')
			{
				strcat (extenso, "onze bilhoes ");
			}
			else if (numero[i - 1] == '2')
			{
				strcat (extenso, "doze bilhoes ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "treze bilhoes ");
			}
			else if (numero[i - 1] == '4')
			{
				strcat (extenso, "catorze bilhoes ");
			}
			else if (numero[i - 1] == '5')
			{
				strcat (extenso, "quinze bilhoes ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "dezesseis bilhoes ");
			}
			else if (numero[i - 1] == '7')
			{
				strcat (extenso, "dezessete bilhoes ");
			}
			else if (numero[i - 1] == '8')
			{
				strcat (extenso, "dezoito bilhoes ");
			}
			else if (numero[i - 1] == '9')
			{
				strcat (extenso, "dezenove bilhoes ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Dez bilhoes ");
			}
			else if (numero[i - 1] == '1')
			{
				strcat (extenso, "Onze bilhoes ");
			}
			else if (numero[i - 1] == '2')
			{
				strcat (extenso, "Doze bilhoes ");
			}
			else if (numero[i - 1] == '3')
			{
				strcat (extenso, "Treze bilhoes ");
			}
			else if (numero[i - 1] == '4')
			{
				strcat (extenso, "Catorze bilhoes ");
			}
			else if (numero[i - 1] == '5')
			{
				strcat (extenso, "Quinze bilhoes ");
			}
			else if (numero[i - 1] == '6')
			{
				strcat (extenso, "Dezesseis bilhoes ");
			}
			else if (numero[i - 1] == '7')
			{
				strcat (extenso, "Dezessete bilhoes ");
			}
			else if (numero[i - 1] == '8')
			{
				strcat (extenso, "Dezoito bilhoes ");
			}
			else if (numero[i - 1] == '9')
			{
				strcat (extenso, "Dezenove bilhoes ");
			}
		}
	}
	else if (numero[i] == '2')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "vinte bilhoes ");
			}
			else
			{
				strcat (extenso, "vinte e ");
			}	
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Vinte bilhoes ");
			}
			else
			{
				strcat (extenso, "Vinte e ");
			}
		}
	}
	else if (numero[i] == '3')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "trinta bilhoes ");
			}
			else
			{
				strcat (extenso, "trinta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Trinta bilhoes ");
			}
			else
			{
				strcat (extenso, "Trinta e ");
			}
		}
	}
	else if (numero[i] == '4')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "quarenta bilhoes ");
			}
			else
			{
				strcat (extenso, "quarenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Quarenta bilhoes ");
			}
			else
			{
				strcat (extenso, "Quarenta e ");
			}
		}
	}
	else if (numero[i] == '5')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "cinquenta bilhoes ");
			}
			else
			{
				strcat (extenso, "cinquenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Cinquenta bilhoes ");
			}
			else
			{
				strcat (extenso, "Cinquenta e ");
			}
		}
	}
	else if (numero[i] == '6')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "sessenta bilhoes ");
			}
			else
			{
				strcat (extenso, "sessenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Sessenta bilhoes ");
			}
			else
			{
				strcat (extenso, "Sessenta e ");
			}
		}
	}
	else if (numero[i] == '7')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "setenta bilhoes ");
			}
			else
			{
				strcat (extenso, "setenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Setenta bilhoes ");
			}
			else
			{
				strcat (extenso, "Setenta e ");
			}
		}
	}
	else if (numero[i] == '8')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "oitenta bilhoes ");
			}
			else
			{
				strcat (extenso, "oitenta e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Oitenta bilhoes ");
			}
			else
			{
				strcat (extenso, "Oitenta e ");
			}
		}
	}
	else if (numero[i] == '9')
	{
		if (contagem >= 12)
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "noventa bilhoes ");
			}
			else
			{
				strcat (extenso, "noventa e ");
			}
		}
		else
		{
			if (numero[i - 1] == '0')
			{
				strcat (extenso, "Noventa bilhoes ");
			}
			else
			{
				strcat (extenso, "Noventa e ");
			}
		}
	}
}

//Numero por extenso, centena de bilhao
void Extenso_P12 (char numero[], char extenso[], int i, int contagem)
{
	if (numero[i] == '1')
	{
		if (numero[i - 1] == '0' && numero[i - 2] == '0')
		{
			strcat (extenso, "Cem milhoes,");
		}
		else
		{
			strcat (extenso, "Cento e ");
		}
	}
	else if (numero[i] == '2')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			strcat (extenso, "Duzentos milhoes,");
		}
		else
		{
			strcat (extenso, "Duzentos e ");
		}
	}
	else if (numero[i] == '3')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			strcat (extenso, "Trezentos milhoes,");
		}
		else
		{
			strcat (extenso, "Trezentos e ");
		}
	}
	else if (numero[i] == '4')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			strcat (extenso, "Quatrocentos milhoes,");
		}
		else
		{
			strcat (extenso, "Quatrocentos e ");
		}
	}
	else if (numero[i] == '5')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			strcat (extenso, "Quinhentos milhoes,");
		}
		else
		{
			strcat (extenso, "Quinhentos e ");
		}
	}
	else if (numero[i] == '6')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			strcat (extenso, "Seiscentos milhoes,");
		}
		else
		{
			strcat (extenso, "Seiscentos e ");
		}
	}
	else if (numero[i] == '7')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			strcat (extenso, "Setecentos milhoes,");
		}
		else
		{
			strcat (extenso, "Setecentos e ");
		}
	}
	else if (numero[i] == '8')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			strcat (extenso, "Oitocentos milhoes,");
		}
		else
		{
			strcat (extenso, "Oitocentos e ");
		}
	}
	else if (numero[i] == '9')
	{
		if (numero[i - 1] == '0' && numero[contagem - 2] == '0')
		{
			strcat (extenso, "Novecentos milhoes,");
		}
		else
		{
			strcat (extenso, "Novecentos e ");
		}
	}
}

//Printa a string para Centibits
void Printa_Ext_Centibits (char Cheque[], char Extenso[], int contagem)
{
	int i;
	strcpy (Extenso, "");
	for (i = contagem; i >= 0; i--)
	{
		if (i == 0)
		{
			if (Cheque[0] == '0')
			{
				strcpy (Extenso, "zero");
			}
			else
			{
				Extenso_CP1 (Cheque, Extenso, i, contagem);
			}
		}
		else if (i == 1)
		{
			Extenso_CP2 (Cheque, Extenso, i);
		}
	}
	strcat (Extenso, " CentBits");
	printf ("e %s", Extenso);
}

//Printa a string para Bits
void Printa_Ext_Bits (char Cheque[], char Extenso[], int contagem)
{
	int i;
	strcpy (Extenso, "");
	for (i = contagem; i >= 0; i--)
	{
		if (i == 0)
		{
			Extenso_P1 (Cheque, Extenso, i, contagem);
		}
		else if (i == 1)
		{
			Extenso_P2 (Cheque, Extenso, i, contagem);
		}
		else if (i == 2)
		{
			Extenso_P3 (Cheque, Extenso, i, contagem);
		}
		else if (i == 3)
		{
			Extenso_P4 (Cheque, Extenso, i, contagem);
		}
		else if (i == 4)
		{
			Extenso_P5 (Cheque, Extenso, i, contagem);
		}
		else if (i == 5)
		{
			Extenso_P6 (Cheque, Extenso, i, contagem);
		}
		else if (i == 6)
		{
			Extenso_P7 (Cheque, Extenso, i, contagem);
		}
		else if (i == 7)
		{
			Extenso_P8 (Cheque, Extenso, i, contagem);
		}
		else if (i == 8)
		{
			Extenso_P9 (Cheque, Extenso, i, contagem);
		}
		else if (i == 9)
		{
			Extenso_P10 (Cheque, Extenso, i, contagem);
		}
		else if (i == 10)
		{
			Extenso_P11 (Cheque, Extenso, i, contagem);
		}
		else if (i == 11)
		{
			Extenso_P12 (Cheque, Extenso, i, contagem);
		}
	}
	printf ("Cheque preenchido:\n\t");
	strcat (Extenso, " Bits");
	printf ("%s ", Extenso);
}

//Data
struct Data
{
	int Dia, Mes, Ano;
};

int main()
{
	int Contagem_Bits, Contagem_Centi, i;
	char Senha[7], Cheque_Bits[16], Cheque_Centi[4], Extenso_Bits[200], Extenso_Centi[200], Mes_por_Extenso[50];
	double Salario;
	char Resposta_02, Resposta_01;
	struct tm tempo;
	struct Data Preenchido;
	time_t Tempo_em_Seg;
	time (&Tempo_em_Seg);
	tempo = *localtime (&Tempo_em_Seg);
	printf("Por favor digite sua senha do Banco: ");
	Ler_Senha(Senha);
	system ("cls");
	if (Comparacao_de_Senhas(Senha) != 0)
	{
		do
		{
			printf("Senha incorreta.\nTente novamente: ");
			Ler_Senha (Senha);
			system ("cls");
		}
		while (Comparacao_de_Senhas(Senha) != 0);
	}
	printf ("Senha correta.\n");
	do
	{
		printf ("Por favor, escolha uma das duas opcoes:\n\t1 - Quantas notas voce recebera no saque\n\t2 - Preenchimento de cheques\n\tResposta: ");
		scanf ("%s", &Resposta_01);
		if (Resposta_01 != 1 && Resposta_01 != 2)
		{
			do
			{
				system ("cls");
				printf ("Resposta invalida, por favor, digite uma resposta valida:\n\t1 - Quantas notas voce recebera no saque\n\t2 - Preenchimento de cheques\n\tResposta: ");
				scanf ("%d", &Resposta_01);
			}
			while (Resposta_01 != 1 && Resposta_01 != 2);
		}
		if (Resposta_01 == 1)
		{
			system ("cls");
			printf ("Digite a quantidade do saque (Por favor, separe os bits e centibits por ponto,\ne nao virgula, senao o sistema nao reconhecera os centibits): ");
			Ler_Salario (&Salario);
			system ("cls");
			Print_Notas (Salario);
		}
		else if (Resposta_01 == 2)
		{
			system ("cls");
			Ler_Cheque (Cheque_Bits, Cheque_Centi);
			Preenchido.Dia = tempo.tm_mday;
			Preenchido.Mes = tempo.tm_mon + 1;
			Preenchido.Ano = tempo.tm_year + 1900;
			if (Preenchido.Mes == 1)
			{
				strcpy (Mes_por_Extenso, "janeiro");
			}
			else if (Preenchido.Mes == 2)
			{
				strcpy (Mes_por_Extenso, "fevereiro");
			}
			else if (Preenchido.Mes == 3)
			{
				strcpy (Mes_por_Extenso, "marco");
			}
			else if (Preenchido.Mes == 4)
			{
				strcpy (Mes_por_Extenso, "abril");
			}
			else if (Preenchido.Mes == 5)
			{
				strcpy (Mes_por_Extenso, "maio");
			}
			else if (Preenchido.Mes == 6)
			{
				strcpy (Mes_por_Extenso, "junho");
			}
			else if (Preenchido.Mes == 7)
			{
				strcpy (Mes_por_Extenso, "julho");
			}
			else if (Preenchido.Mes == 8)
			{
				strcpy (Mes_por_Extenso, "agosto");
			}
			else if (Preenchido.Mes == 9)
			{
				strcpy (Mes_por_Extenso, "setembro");
			}
			else if (Preenchido.Mes == 10)
			{
				strcpy (Mes_por_Extenso, "outubro");
			}
			else if (Preenchido.Mes == 11)
			{
				strcpy (Mes_por_Extenso, "novembro");
			}
			else if (Preenchido.Mes == 12)
			{
				strcpy (Mes_por_Extenso, "dezembro");
			}
			Contagem_Bits = strlen (Cheque_Bits);
			Contagem_Centi = strlen (Cheque_Centi);
			system ("cls");
			Printa_Ext_Bits (Cheque_Bits, Extenso_Bits, Contagem_Bits);
			Printa_Ext_Centibits (Cheque_Centi, Extenso_Centi, Contagem_Centi);
			printf (".\n\tDia %02d de %s de %02d", Preenchido.Dia, Mes_por_Extenso, Preenchido.Ano);
		}
		printf ("\n");
		printf ("Gostaria de realizar mais uma operacao? (s/n): ");
		scanf ("%s", &Resposta_02);
		if (Resposta_02 != 's' && Resposta_02 != 'S' && Resposta_02 != 'n' && Resposta_02 != 'N')
		{
			do
			{
				system ("cls");
				printf ("Resposta invalida, por favor digite uma resposta valida (s/n): ");
				scanf ("%s", &Resposta_02);
			}
			while (Resposta_02 != 's' && Resposta_02 != 'S' && Resposta_02 != 'n' && Resposta_02 != 'N');
		}
		system ("cls");
		strcpy (Extenso_Bits, "");
		strcpy (Extenso_Centi, "");
	}
	while (Resposta_02 == 's' || Resposta_02 == 'S');
	return 0;
}
