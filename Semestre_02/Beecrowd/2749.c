/*Nesse exercício, eu usei o for para 
evitar ter que dar prints muito longos*/
#include <stdio.h>
int main ()
{
	int i;
	for (i = 0; i < 39; i++)
	{
		printf ("-");
	}
	printf ("\n|x = 35");
	for (i = 6; i < 37; i++)
	{
		printf (" ");
	}
	printf ("|\n");
	printf ("|");
	for (i = 1; i < 38; i++)
	{
		printf (" ");
	}
	printf ("|\n");
	printf ("|");
	for (i = 1; i < 16; i++)
	{
		printf (" ");
	}
	printf ("x = 35");
	for (i = 23; i < 39; i++)
	{
		printf (" ");
	}
	printf ("|\n");
	printf ("|");
	for (i = 1; i < 38; i++)
	{
		printf(" ");
	}
	printf ("|\n");
	printf ("|");
	for (i = 1; i < 32; i++)
	{
		printf (" ");
	}
	printf ("x = 35|\n");
	for (i = 0; i < 39; i++)
	{
		printf ("-");
	}
	printf("\n");
	return 0;
}
