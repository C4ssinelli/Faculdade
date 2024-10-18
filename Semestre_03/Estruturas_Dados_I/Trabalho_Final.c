// Este trabalho implementa vários tipos de Hashes, apresentando:
/* 
    -> O método do resto da divisão inteira
    -> Função de Transformação pela Raiz
    -> Função de Enlaçamento Deslocado
    -> Método de Encadeamento
    -> Método da Tentativa Linear
*/

//Feito por:
//Nome: Alex Cassinelli, RA: 211021849
//Nome: Vinicius Garcia, RA: 211020681

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 1000

int convert(int number, int base)
{
    if (number == 0 || base == 10)
        return number;

    return (number % base) + 10 * convert(number / base, base);
}

void Divisao_Inteira(long int Chave_Original, int *Chave_Temporaria, int M)
{
    (*Chave_Temporaria) = Chave_Original % M;
}

void Transformacao_da_Raiz(long int Chave_Original, int *Chave_Temporaria, int M, int base)
{
    *Chave_Temporaria = convert(Chave_Original, base) % M;
}

void Enlacamento_Deslocado(long int Chave_Original, int *Chave_Temporaria, int M)
{

    int tamM = floor(log10(abs(M))) + 1;
    int tamB;
    int divisor = 1;
    int i;

    for (i = 1; i <= tamM; i++)
    {
        divisor = divisor * 10;
    }

    do
    {
        *Chave_Temporaria = 0;

        while (Chave_Original > 0)
        {
            int resto = Chave_Original % divisor;
            Chave_Original /= divisor;

            *Chave_Temporaria += resto;
        }

        Chave_Original = *Chave_Temporaria;
        divisor /= 10;

    } while (Chave_Original > M);
}

void Encadeamento(long int Vetor_Chaves[][2], int Hash_Chave, long int Chave, int M)
{

    int Entrada_Chave = Hash_Chave;
    int fim = 0;
    int ciclo = 0;
    int aux = -1;

    do
    {

        if (Vetor_Chaves[Entrada_Chave][0] == -1)
        {
            Vetor_Chaves[Entrada_Chave][0] = Chave;
            fim = 1;
            // printf("Coloquei %ld em %d\n", Chave, Entrada_Chave);
        }
        else
        {
            // printf("Nao foi possivel Colocar %ld em %d\n", Chave, Entrada_Chave);

            if (Vetor_Chaves[Entrada_Chave][1] != -1)
            {
                // o pointer tem algo
                Entrada_Chave = Vetor_Chaves[Entrada_Chave][1];
                // printf("Talvez possivel colocar %ld em %d\n", Chave, Entrada_Chave);
            }
            else
            {
                // pointer é -1
                if (ciclo == 0)
                {
                    // tenta o valor mais baixo da tabela
                    // printf(">Iniciei o ciclo\n");
                    ciclo = 1;
                    Entrada_Chave = M - 1;
                }
                else
                {
                    if (Entrada_Chave > 0)
                    {
                        // printf(">Chave Maior que zero\n");
                        Vetor_Chaves[Entrada_Chave][1] = Entrada_Chave - 1;
                        Entrada_Chave--;
                    }
                    else
                    {
                        // printf(">Resetei o contador\n");
                        Vetor_Chaves[Entrada_Chave][1] = M;
                        Entrada_Chave = M - 1;
                    }
                }

                // printf("Proxima It %ld em %d\n", Chave, Entrada_Chave);
            }
            // printf(">> Entrada Chave %d\n", Entrada_Chave);
        }
    } while (fim == 0);
}

void Tentativa_Linear(long int Vetor_Chaves[], int Chave_Temporaria, long int Chave, int M)
{
    int Aux;
    Aux = Chave_Temporaria;
    if (Vetor_Chaves[Aux] != -1)
    {
        while (Vetor_Chaves[Aux] != -1)
        {
            if (Aux == M - 1)
            {
                Aux = 0;
            }
            else
            {
                Aux++;
            }
        }
    }
    Vetor_Chaves[Aux] = Chave;
}

// So serve para Tentativa Linear (fazer um segundo para Encadeamento)
int Encontra_Tentativa_Linear(long int Vetor_Chaves[], long int Chave_Original, int Chave_Temporaria, int M)
{
    int Aux;
    Aux = Chave_Temporaria;
    if (Vetor_Chaves[Aux] != Chave_Original)
    {
    	if(Vetor_Chaves[Aux] == -1)
    	{
    		return 0;
		}
        while (Vetor_Chaves[Aux] != Chave_Original)
        {
            if (Aux == M - 1)
            {
                Aux = 0;
            }
            else
            {
                Aux++;
            }
        }
    }
    if (Vetor_Chaves[Aux] == Chave_Original)
    {
        return 1;
    }
    return 0;
}

int Encontra_Encadeamento(long int Vetor_Chaves[][2], long int Chave_Original, int Chave_Temporaria, int M)
{
    int Aux;
    Aux = Chave_Temporaria;
    if (Vetor_Chaves[Aux][0] != Chave_Original)
    {
    	if(Vetor_Chaves[Aux][0] == -1)
    	{
    		return 0;
		}
        while (Vetor_Chaves[Aux][0] != Chave_Original)
        {
            Aux = Vetor_Chaves[Aux][1];
        }
    }
    if (Vetor_Chaves[Aux][0] == Chave_Original)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int Resposta_01, Resposta_02, M, i, Chave_Temporaria, Base;
    long int Vetor_Chaves_Linear[MAX], Vetor_Chaves_Encadeamento[MAX][2], Chave_Original, Chave_Quadrado, Chave_Enlacamento;
    char Resposta_03, Resposta_04;
    char Chave_Grande[MAX][MAX], Chave_Extracao[MAX];
    for (i = 0; i < MAX; i++)
    {
        Vetor_Chaves_Linear[i] = -1;
        Vetor_Chaves_Encadeamento[i][0] = -1;
        Vetor_Chaves_Encadeamento[i][1] = -1;
    }
    printf("Ola! Por favor, digite o tamanho maximo do vetor (M): ");
    scanf("%d", &M);
    system("cls");
    printf("Por favor, escolha seu metodo de hashing:\n\t1 - Resto de divisao inteira\n\t2 - Meio Quadrado\n\t3 - Enlacamento Deslocado");
    printf("\n");
    do
    {
        printf("\tResposta: ");
        scanf("%d", &Resposta_01);
    }while (Resposta_01 < 1 || Resposta_01 > 3);
    system("cls");
    printf("Por favor, escolha seu metodo de tratamento de colisao:\n\t1 - Encadeamento\n\t2 - Tentativa Linear");
    printf("\n");
    do
    {
        printf("\tResposta: ");
        scanf("%d", &Resposta_02);
    }while (Resposta_02 < 1 || Resposta_02 > 2);
    system("cls");
    if (Resposta_01 == 1)
    {
        int i = 0;
        while (Resposta_03 != 'N')
        {
            printf("Por favor, digite sua chave: ");
            scanf("%ld", &Chave_Original);
            Divisao_Inteira(Chave_Original, &Chave_Temporaria, M);
            if (Resposta_02 == 1)
            {
                Encadeamento(Vetor_Chaves_Encadeamento, Chave_Temporaria, Chave_Original, M);
                printf("Gostaria de encontrar alguma chave digitada anteriormente? (S/N)\n\tResposta: ");
                Resposta_04 = toupper(getche());
                printf("\n");
                while (Resposta_04 == 'S')
                {
                    printf("Digite a chave que gostaria de recuperar: ");
                    scanf("%ld", &Chave_Original);
                    printf("\n");
                    Divisao_Inteira(Chave_Original, &Chave_Temporaria, M);
                    if (Encontra_Encadeamento(Vetor_Chaves_Encadeamento, Chave_Original, Chave_Temporaria, M) == 1)
                    {
                        printf("A chave esta armazenada no vetor\n");
                    }
                    else
                    {
                        printf("A chave nao esta armazenada no vetor\n");
                    }
                    printf("Gostaria de checar outra chave? (S/N)\n\tResposta: ");
                    Resposta_04 = toupper(getche());
                    printf("\n");
                }
            }
            else
            {
                Tentativa_Linear(Vetor_Chaves_Linear, Chave_Temporaria, Chave_Original, M);
                printf("Gostaria de encontrar alguma chave digitada anteriormente? (S/N)\n\tResposta: ");
                Resposta_04 = toupper(getche());
                printf("\n");
                while (Resposta_04 == 'S')
                {
                    printf("Digite a chave que gostaria de recuperar: ");
                    scanf("%ld", &Chave_Original);
                    printf("\n");
                    Divisao_Inteira(Chave_Original, &Chave_Temporaria, M);
                    if (Encontra_Tentativa_Linear(Vetor_Chaves_Linear, Chave_Original, Chave_Temporaria, M) == 1)
                    {
                        printf("A chave esta armazenada no vetor\n");
                    }
                    else
                    {
                        printf("A chave nao esta armazenada no vetor\n");
                    }
                    printf("Gostaria de checar outra chave? (S/N)\n\tResposta: ");
                    Resposta_04 = toupper(getche());
                    printf("\n");
                }
            }
            printf("Gostaria de tentar novamente? (s/n)\n\tResposta: ");
            do
            {
                Resposta_03 = toupper(getche());
            } while (Resposta_03 != 'S' && Resposta_03 != 'N');
            system("cls");
        }
    }
    else if (Resposta_01 == 2)
    {
    	printf("Por favor, digite a base: ");
        scanf("%d", &Base);
        while (Resposta_03 != 'N')
        {
            printf("Por favor, digite sua chave: ");
            scanf("%d", &Chave_Quadrado);
            Transformacao_da_Raiz(Chave_Quadrado, &Chave_Temporaria, M, Base);
            if (Resposta_02 == 1)
            {
                Encadeamento(Vetor_Chaves_Encadeamento, Chave_Temporaria, Chave_Quadrado, M);
                printf("Gostaria de encontrar alguma chave digitada anteriormente? (S/N)\n\tResposta: ");
                printf("\n");
                Resposta_04 = toupper(getche());
                while (Resposta_04 == 'S')
                {
                    printf("Digite a chave que gostaria de recuperar: ");
                    scanf("%ld", &Chave_Quadrado);
                    printf("\n");
                    Transformacao_da_Raiz(Chave_Quadrado, &Chave_Temporaria, M, Base);
                    if (Encontra_Encadeamento(Vetor_Chaves_Encadeamento, Chave_Quadrado, Chave_Temporaria, M) == 1)
                    {
                        printf("A chave esta armazenada no vetor\n");
                    }
                    else
                    {
                        printf("A chave nao esta armazenada no vetor\n");
                    }
                    printf("Gostaria de checar outra chave? (S/N)\n\tResposta: ");
                    Resposta_04 = toupper(getche());
                    printf("\n");
                }
            }
            else
            {
                Tentativa_Linear(Vetor_Chaves_Linear, Chave_Temporaria, Chave_Quadrado, M);
                printf("Gostaria de encontrar alguma chave digitada anteriormente? (S/N)\n\tResposta: ");
                Resposta_04 = toupper(getche());
                printf("\n");
                while (Resposta_04 == 'S')
                {
                    printf("Digite a chave que gostaria de recuperar: ");
                    scanf("%ld", &Chave_Quadrado);
                    printf("\n");
                    Transformacao_da_Raiz(Chave_Quadrado, &Chave_Temporaria, M, Base);
                    if (Encontra_Tentativa_Linear(Vetor_Chaves_Linear, Chave_Quadrado, Chave_Temporaria, M) == 1)
                    {
                        printf("A chave esta armazenada no vetor\n");
                    }
                    else
                    {
                        printf("A chave nao esta armazenada no vetor\n");
                    }
                    printf("Gostaria de checar outra chave? (S/N)\n\tResposta: ");
                    Resposta_04 = toupper(getche());
                    printf("\n");
                }
            }
            printf("Gostaria de tentar novamente? (s/n)\n\tResposta: ");
            do
            {
                Resposta_03 = toupper(getche());
            } while (Resposta_03 != 'S' && Resposta_03 != 'N');
            system("cls");
        }
    }
    else if(Resposta_01 == 3)
    {
        while (Resposta_03 != 'N')
        {
            printf("Por favor, digite sua chave: ");
            scanf("%d", &Chave_Enlacamento);
            Enlacamento_Deslocado(Chave_Enlacamento, &Chave_Temporaria, M);
            if (Resposta_02 == 1)
            {
                Encadeamento(Vetor_Chaves_Encadeamento, Chave_Temporaria, Chave_Enlacamento, M);
                printf("Gostaria de encontrar alguma chave digitada anteriormente? (S/N)\n\tResposta: ");
                Resposta_04 = toupper(getche());
                printf("\n");
                while (Resposta_04 == 'S')
                {
                    printf("Digite a chave que gostaria de recuperar: ");
                    scanf("%ld", &Chave_Enlacamento);
                    printf("\n");
                    Enlacamento_Deslocado(Chave_Enlacamento, &Chave_Temporaria, M);
                    if (Encontra_Encadeamento(Vetor_Chaves_Encadeamento, Chave_Enlacamento, Chave_Temporaria, M) == 1)
                    {
                        printf("A chave esta armazenada no vetor\n");
                    }
                    else
                    {
                        printf("A chave nao esta armazenada no vetor\n");
                    }
                    printf("Gostaria de checar outra chave? (S/N)\n\tResposta: ");
                    Resposta_04 = toupper(getche());
                    printf("\n");
                }
            }
            else
            {
                Tentativa_Linear(Vetor_Chaves_Linear, Chave_Temporaria, Chave_Enlacamento, M);
                printf("Gostaria de encontrar alguma chave digitada anteriormente? (S/N)\n\tResposta: ");
                Resposta_04 = toupper(getche());
                printf("\n");
                while (Resposta_04 == 'S')
                {
                    printf("Digite a chave que gostaria de recuperar: ");
                    scanf("%ld", &Chave_Enlacamento);
                    printf("\n");
                    Enlacamento_Deslocado(Chave_Enlacamento, &Chave_Temporaria, M);
                    if (Encontra_Tentativa_Linear(Vetor_Chaves_Linear, Chave_Enlacamento, Chave_Temporaria, M) == 1)
                    {
                        printf("A chave esta armazenada no vetor\n");
                    }
                    else
                    {
                        printf("A chave nao esta armazenada no vetor\n");
                    }
                    printf("Gostaria de checar outra chave? (S/N)\n\tResposta: ");
                    Resposta_04 = toupper(getche());
                    printf("\n");
                }
            }
            printf("Gostaria de tentar novamente? (s/n)\n\tResposta: ");
            do
            {
                Resposta_03 = toupper(getche());
            } while (Resposta_03 != 'S' && Resposta_03 != 'N');
            system("cls");
        }
    }
    printf("\nObrigado por utilizar o programa!");
    return 0;
}
