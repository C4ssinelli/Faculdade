/*Eu usei a biblioteca de strings para utilizar da funcao strcmp para ordenar as palavras,
ja que a funcao verifica se as strings sao alfabeticamente iguais, maiores, ou menores*/
#include <stdio.h>
#include <string.h>
#define max 21
int main ()
{
	char p1[max], p2[max];
	scanf ("%s %s", p1, p2);
	if (strcmp (p1, p2) > 0)
	{
		printf ("%s\n%s\n", p2, p1);
	}
	else if (strcmp (p1, p2) < 0)
	{
		printf ("%s\n%s\n", p1, p2);
	}
	return 0;
}
