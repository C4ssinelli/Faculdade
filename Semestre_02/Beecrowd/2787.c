/*Eu percebi que o que define se a última casa será preta ou branca, 
é se a soma das linhas e colunas é par ou ímpar, então usei uma variável para soma,
e os ifs para conferir e responder de acordo.*/
#include <stdio.h>
int main ()
{
	int l, c, S=0;
	scanf("%d %d", &l, &c);
	S = l + c;
	if(S % 2 == 0)
	{
		printf("1\n");
	}
	else if(S % 2 != 0)
	{
		printf("0\n");
	}
	return 0;
}
