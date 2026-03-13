#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 50000
int main ()
{
    int tmp,i=0,j=0,continua=1,contador=0;
    int vetor[TAMANHO];
    inicio_preenchimento:
        if (i>TAMANHO) goto fim_preenchimento;
        vetor[i] = rand()%TAMANHO;
        i++;
        goto inicio_preenchimento;
    fim_preenchimento:
    i=0;
    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();
    inicio_externo:
        if(continua == 0 || i > TAMANHO) goto fim_externo;
        continua = 0;
        inicio_interno:
            if (j > TAMANHO-i-1) goto fim_interno;
            if(vetor[j] < vetor[j+1])
            {
                continua = 1;
                tmp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = tmp;
            }
            j++;
            goto inicio_interno;
        fim_interno:
        i++;
        j = 0;
        goto inicio_externo;
    fim_externo:
    fim = clock();

    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %f segundos\n", tempo_gasto);
    //int k = 0;
    //inicio_exibir:
        //if (k > TAMANHO) goto fim_exibir;
        //printf(" %d ",vetor[k]);
        //k++;
        //goto inicio_exibir; 
    //fim_exibir:
}