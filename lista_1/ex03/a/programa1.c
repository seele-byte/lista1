#include <stdio.h>
#include <stdlib.h>

void exibir_vetor(int *vetor);
void bubble_sort(int *vetor);
void selection_sort(int *vetor);
void insertion_sort(int *vetor);
int main()
{
    int v1[10],v2[10],v3[10],i=0;
    inicio:
        if (i > 9) goto fim;
        v1[i] = rand()%100;
        v2[i] = rand()%100;
        v3[i] = rand()%100;
        i++;
        goto inicio;
    fim:
    printf("Vetor 1 Desordenado: ");
    exibir_vetor(v1);
    bubble_sort(v1);
    printf("Vetor 1 Ordenado: ");
    exibir_vetor(v1);
    printf("\n");
    printf("Vetor 2 Desordenado: ");
    exibir_vetor(v2);
    selection_sort(v2);
    printf("Vetor 2 Ordenado: ");
    exibir_vetor(v2);
    printf("\n");
    printf("Vetor 3 Desordenado: ");
    exibir_vetor(v3);
    insertion_sort(v3);
    printf("Vetor 3 Ordenado: ");
    exibir_vetor(v3);
}
void exibir_vetor(int *vetor)
{
    int i = 0;
    inicio_exibir:
        if (i > 9) goto fim_exibir;
        printf(" %d ",vetor[i]);
        i++;
        goto inicio_exibir;
    fim_exibir:
    printf("\n");
}
void bubble_sort(int *vetor) 
{
    int continua = 1;
    int tmp,i=0,j=0;
    inicio_externo:
        if(continua == 0 || i == 9) goto fim_externo;
        continua = 0;
        inicio_interno:
            if (j > 8-i) goto fim_interno;
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
}

void selection_sort(int *vetor)
{
    int menor,tmp,i=0,j=1;
    inicio_externo:
        if (i > 8) goto fim_externo;
        menor = i;
        inicio_interno:
            if (j>9) goto fim_interno;
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
}
void insertion_sort(int *vetor)
{
    int i = 1,j,atual;
    inicio_externo:
        if (i == 10) goto fim_externo;
        atual = vetor[i];
        j = i;
        inicio_interno:
            if(j == 0 || atual > vetor[j-1]) goto fim_interno;
            vetor[j] = vetor[j-1];
            j--;
            goto inicio_interno;
        fim_interno:
        vetor[j] = atual;
        i++;
        goto inicio_externo;
    fim_externo:
}