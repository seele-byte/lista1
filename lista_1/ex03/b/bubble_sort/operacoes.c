#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100000
int main ()
{
    int tmp,i=0,j=0,continua=1,contador=0;
    long long comparacoes=0,atribuicoes=0;
    int vetor[TAMANHO];
    inicio_preenchimento:
        if (i>TAMANHO) goto fim_preenchimento;
        vetor[i] = rand()%TAMANHO;
        i++;
        goto inicio_preenchimento;
    fim_preenchimento:
    i=0;

    inicio_externo:
        comparacoes += 2;
        if(continua == 0 || i > TAMANHO) goto fim_externo;
        continua = 0;
        atribuicoes += 1;
        inicio_interno:
            comparacoes += 1;
            if (j > TAMANHO-i-1) goto fim_interno;
            comparacoes += 1;
            if(vetor[j] < vetor[j+1])
            {
                continua = 1;
                tmp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = tmp;
                atribuicoes += 4;
            }
            j++;
            atribuicoes += 1;
            goto inicio_interno;
        fim_interno:
        i++;
        j = 0;
        atribuicoes+= 2;
        goto inicio_externo;
    fim_externo:
    printf("Numero de comparações : %lld \n Numero de Atribuições: %lld",comparacoes,atribuicoes);
}