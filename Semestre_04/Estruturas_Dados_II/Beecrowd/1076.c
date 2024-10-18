/*O exercicio trata-se de uma DFS, vou usar uma matriz 
de adjacencia para representar o grafo e, fazer uma 
busca recursiva sobre o mesmo*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int Contador = 0;

int DFS(int Labirinto[][MAX], int Vetor_Passou[], int No_Inicial)
{
	int i;
	Vetor_Passou[No_Inicial] = 1;
	for(i = 0; i < MAX; i++)
	{
		if(Labirinto[No_Inicial][i] == 1)
		{
			if(Vetor_Passou[i] == 0)
			{
				Contador+=2;
				DFS(Labirinto, Vetor_Passou, i);
			}
		}
	}
}

int main()
{
	int T, N, V, A, Origem, Destino;
	int i, j, k;
	int Labirinto[MAX][MAX], Vetor_Passou[MAX];
	scanf("%d", &T);
	for(i = 0; i < T; i++)
	{
		Contador = 0;
		scanf("%d", &N);
		scanf("%d %d", &V, &A);
		for(j = 0; j < V; j++)
		{
			for(k = 0; k < MAX; k++)
			{
				Labirinto[j][k] = 0;
			}
			Vetor_Passou[j] = 0;
		}
		for(j = 0; j < A; j++)
		{
			scanf("%d %d", &Origem, &Destino);
			Labirinto[Origem][Destino] = 1;
			Labirinto[Destino][Origem] = 1;
		}
		DFS(Labirinto, Vetor_Passou, N);
		printf("%d\n", Contador);
	}
	return 0;
}
