/*Eu escrevi a sequencia de Fibonacci, colocando os valores eu um vetor,
depois mandei o programa printar o vetor invertido*/
#include <stdio.h>
#define max 40
int main ()
{
	int n,i,j;
	long int v[max];
	scanf("%d",&n);
	v[0]=1;
	v[1]=1;
	for(i=2;i<n;i++)
	{
		v[i]=v[i-2]+v[i-1];
	}
	for(i=n-1;i>=1;i--)
	{
		printf("%d ",v[i]);
	}
	printf("%d\n",v[0]);
	return 0;
}
