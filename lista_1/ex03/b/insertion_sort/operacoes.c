#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50000
int main ()
{
    int tmp,i=0,atual,contador=0,j;
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
        if (i > TAMANHO) goto fim_externo;
        atual = vetor[i];
        j = i;
        atribuicoes+=2;
        inicio_interno:
            if(j == 0 || atual > vetor[j-1]) goto fim_interno;
            vetor[j] = vetor[j-1];
            j--;
            atribuicoes += 2;
            comparacoes += 2;
            goto inicio_interno;
        fim_interno:
        vetor[j] = atual;
        i++;
        atribuicoes += 2;
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