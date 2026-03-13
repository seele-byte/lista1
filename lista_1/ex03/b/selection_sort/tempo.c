#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 50000
int main ()
{
    int tmp,i=0,menor,j=1;
    int vetor[TAMANHO];
    inicio_preenchimento:
        if (i>TAMANHO) goto fim_preenchimento;
        vetor[i] = rand()%TAMANHO;
        i++;
        goto inicio_preenchimento;
    fim_preenchimento:
    clock_t inicio, fim;
    double tempo_gasto;
    inicio = clock();
    i = 1;
    inicio_externo:
        if (i > TAMANHO-2) goto fim_externo;
        menor = i;
        inicio_interno:
            if (j>TAMANHO-1) goto fim_interno;
            if( vetor[j] < vetor[menor]) 
            {
                menor = j;
            }
            j++;
            goto inicio_interno;
        fim_interno:
        if (menor != i)
        {
            tmp = vetor[menor];
            vetor[menor] = vetor[i];
            vetor[i] = tmp;
        }
        i++;
        j = i + 1;
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