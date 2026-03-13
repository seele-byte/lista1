#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50000
int main ()
{
    int tmp,i=0,menor,j=1;
    long long comparacoes=0,atribuicoes=0;
    int vetor[TAMANHO];
    inicio_preenchimento:
        if (i>TAMANHO) goto fim_preenchimento;
        vetor[i] = rand()%TAMANHO;
        i++;
        goto inicio_preenchimento;
    fim_preenchimento:
    i = 1;
    inicio_externo:
        if (i > TAMANHO-2) goto fim_externo;
        menor = i;
        atribuicoes += 1;
        inicio_interno:
            if (j>TAMANHO-1) goto fim_interno;
            comparacoes += 1;
            if( vetor[j] < vetor[menor]) 
            {
                menor = j;
                comparacoes += 1;
                atribuicoes += 1;
            }
            j++;
            goto inicio_interno;
        fim_interno:
        
        if (menor != i)
        {
            tmp = vetor[menor];
            vetor[menor] = vetor[i];
            vetor[i] = tmp;
            atribuicoes += 3;
        }
        i++;
        j = i + 1;
        goto inicio_externo;
    fim_externo:

    printf("Numero de comparações : %lld \n Numero de Atribuições: %lld",comparacoes,atribuicoes);
    //int k = 0;
    //inicio_exibir:
        //if (k > TAMANHO) goto fim_exibir;
        //printf(" %d ",vetor[k]);
        //k++;
        //goto inicio_exibir; 
    //fim_exibir:
}