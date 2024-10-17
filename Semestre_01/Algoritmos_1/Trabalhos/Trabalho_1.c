// Este trabalho realiza operações entre ângulos, como seno e cosseno
// Ele recebe entradas em graus ou radianos e realiza a operação desejada.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main ()
{
	int n,m,i,j,r,k,a,b,pi,l;
	float angulo,x,rad,seno,cosseno,tangente;
	do
	{
		printf("Por favor, diga se voce tem um angulo ou uma relacao trigonometrica, \ncomo seno:\n1 - angulo\n2 - relacao\n");
		scanf("%d",&m);
		if(m!=1 && m!=2)
		{
			printf("Digite uma resposta valida, por favor:\n1 - angulo\n2 - relacao\n");
			do
			{
				scanf("%d",&m);
				printf("Digite uma resposta valida, por favor:\n1 - angulo\n2 - relacao\n");
			}
			while(m!=1 && m!=2);
		}
		system("cls");
		if(m==1)
		{
			printf("Por favor, diga se o angulo sera dado em graus ou radianos:\n1 - radianos\n2 - graus\n");
			scanf("%d",&j);
			if(j!=1 && j!=2)
			{
				printf("Por favor digite uma resposta valida:\n1 - radianos\n2 - graus\n");
				do
				{
					scanf("%d",&j);
					printf("Por favor digite uma resposta valida:\n1 - radianos\n2 - graus\n");
				}
				while(j!=1 && j!=2);
			}
			system("cls");
			if(j==1)
			{
				printf("Por favor, diga em qual forma o numero esta escrito:\n1 - fracao\n2 - decimal\n");
				scanf("%d",&k);
				if(k==1)
				{
					printf("Por favor, diga se o pi esta presente no numero:\n1 - sim\n2 - nao\n");
					scanf("%d/%d",&pi);
					if(pi==1)
					{
						printf("Por favor, digite a fracao, sem o pi, do modo indicado (a/b): ");
						scanf("%d/%d",&a,&b);
						rad=(a*M_PI)/b;
					}
					else if(pi==2)
					{
						printf("Por favor, digite a fracao, do modo indicado (a/b): ");
						scanf("%d/%d",&a,&b);
						rad=a/b;
					}
					else if(pi!=1 && pi!=2)
					{
						printf("Por favor digite uma resposta valida:\n1 - sim\n2 - nao\n");
						do
						{
							scanf("%d",&pi);
							printf("Por favor digite uma resposta valida:\n1 - sim\n2 - nao\n");
						}
						while(pi!=1 && pi!=2);
					}
				}
				else if(k==2)
				{
					printf("Por favor, diga se o angulo apresenta pi:\n1 - sim\n2 - nao\n");
					scanf("%d",&pi);
					if(pi==1)
					{
						printf("Por favor, digite o angulo,sem o pi: ");
						scanf("%f",&angulo);
						rad=angulo*M_PI;
					}
					else if(pi==2)
					{
						printf("Por favor, digite o angulo: ");
						scanf("%f",&angulo);
						rad=angulo;
					}
					else if(pi!=1 && pi!=2)
					{
						printf("Por favor digite uma resposta valida:\n1 - sim\n2 - nao\n");
						do
						{
							scanf("%d",&pi);
							printf("Por favor digite uma resposta valida:\n1 - sim\n2 - nao\n");
						}
						while(pi!=1 && pi!=2);
						system("cls");
					}
				}
				else if(k!=1 && k!=2)
				{
					printf("Por favor digite uma resposta valida:\n1 - fracao\n2 - decimal\n");
					do
					{
						scanf("%d",&k);
						printf("Por favor digite uma resposta valida:\n1 - fracao\n2 - decimal\n");
					}
					while(k!=1 && k!=2);
				}
			}
			else if(j==2)
			{
				printf("Por favor, digite o angulo desejado: ");
				scanf("%f",&angulo);
				rad=angulo*M_PI/180;
			}
			printf("Por favor mostre qual eh a operacao desejada de acordo com a tabela:\n1 - seno\n2 - cosseno\n3 - tangente\n4 - secante\n5 - cossecante\n6 - cotangente\n");
			scanf("%d",&n);
			if(n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6)
			{
				system("cls");
				printf("Por favor, digite uma resposta valida:\n1 - seno\n2 - cosseno\n3 - tangente\n4 - secante\n5 - cossecante\n6 - cotangente\n");
				do
				{
					scanf("%d",&n);
					printf("Por favor, digite uma resposta valida:\n1 - seno\n2 - cosseno\n3 - tangente\n4 - secante\n5 - cossecante\n6 - cotangente\n");
				}
				while(n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6);
			}
			system("cls");
			if(n==1)
			{
				printf("O seno do angulo %.2f rad, digitado eh: %.2f\n",rad,sin(rad));
			}
			if(n==2)
			{
				printf("O cosseno do angulo %.2f rad, digitado eh: %.2f\n",rad,cos(rad));
			}
			if(n==3)
			{
				if(cos(rad)<=0.001)
				{
					printf("A tangente do angulo %.2f rad, digitado nao existe\n",rad);
				}
				else
				{
					printf("A tangente do angulo %.2f rad, digitado eh: %.2f\n",rad,sin(rad)/cos(rad));
				}
			}
			if(n==4)
			{
				if(cos(rad)<=0.001)
				{
					printf("A secante do angulo %.2f rad, digitado nao existe\n",rad);
				}
				else
				{
					printf("A secante do angulo %.2f rad, digitado eh: %.2f\n",rad,1/cos(rad));
				}
			}
			if(n==5)
			{
				printf("A cossecante do angulo %.2f rad, digitado eh: %.2f\n",rad,1/sin(rad));
			}
			if(n==6)
			{
				if(cos(rad)<=0.001)
				{
					printf("A cotangente do angulo %.2f rad, digitado nao existe\n",rad);
				}
				else
				{
					printf("A cotangente do angulo %.2f rad, digitado eh: %.2f\n",rad,1/tan(rad));
				}
			}
		}
		else if(m==2)
		{
			printf("Por favor, digite qual relacao trigonometrica voce possui,\nde acordo com a tabela:\n1 - seno\n2 - cosseno\n3 - tangente\n");
			scanf("%d",&i);
			if(i!=1 && i!=2 && i!=3)
			{
				printf("Por favor, digite um valor valido:\n1 - seno\n2 - cosseno\n3 - tangente\n");
				do
				{
					scanf("%d",&i);
					printf("Por favor, digite um valor valido:\n1 - seno\n2 - cosseno\n3 - tangente\n");
				}
				while(i!=1 && i!=2 && i!=3);
			}
			system("cls");
			if(i==1)
			{
				printf("Por favor, digite o valor do seno: ");
				scanf("%f",&seno);
				if(seno>=0)
				{
					printf("O arco, cujo seno eh %.2f, eh: %.2f e %.2f rad\n",seno,asin(seno),asin(seno)+1.57);
				}
				else
				{
					printf("O arco, cujo seno eh %.2f, eh: %.2f e %.2f rad\n",seno,asin(seno),asin(seno)-1.57);
				}
			}
			if(i==2)
			{
				printf("Por favor, digite o valor do cosseno: ");
				scanf("%f",&cosseno);
				if(cosseno>=0)
				{
					printf("O arco, cujo cosseno eh %.2f, eh: %.2f e %.2f rad\n",cosseno,acos(cosseno),acos(cosseno)+4.71);
				}
				else
				{
					printf("O arco, cujo cosseno eh %.2f, eh: %.2f e %.2f rad\n",cosseno,acos(cosseno),acos(cosseno)-4.71);
				}
			}
			if(i==3)
			{
				printf("Por favor, digite o valor da tangente: ");
				scanf("%f",&tangente);
				if(tangente>=0)
				{
					printf("O arco, cujo tangente eh %.2f, eh: %.2f e %.2f rad\n",tangente,atan(tangente),atan(tangente)+3.14);
				}
				else
				{
					printf("O arco, cujo tangente eh %.2f, eh: %.2f e %.2f rad\n",tangente,atan(tangente),atan(tangente)-3.14);
				}
			}
		}
		printf("Gostaria de repetir a operacao?:\n1 - Sim\n2 - Nao\n");
		do	
		{
			scanf("%d",&r);
			printf("Por favor, digite uma resposta valida:\n1 - Sim\n2 - Nao\n");
		}
		while(r!=1 && r!=2);
		system ("cls");	
	}
	while(r==1);
	return 0;
}
