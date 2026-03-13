#include <stdlib.h>
#include<stdio.h>
typedef struct stnode
{
    int valor;
    struct stnode *prox;
} Node;

typedef struct conjunto
{
    Node *head;
} CONJUNTO;

CONJUNTO* criar_conjunto(){
    CONJUNTO *conjunto = (CONJUNTO*) malloc(sizeof(CONJUNTO));
    if (conjunto == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    conjunto->head = NULL;
    return conjunto;
}
void inserir_elemento(CONJUNTO *conjunto,int inteiro)
{
    if (conjunto->head != NULL)
    {
        Node *tmp1 = conjunto->head;
        while(tmp1 != NULL)
        {
            if (tmp1->valor == inteiro)
            {
                return;
            }
            tmp1 = tmp1->prox;
        }
        tmp1 = NULL;
    }
    Node *elemento = (Node*) malloc(sizeof(Node));
    if (elemento == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    elemento->valor = inteiro;
    if (conjunto->head == NULL)
    {
        conjunto->head = elemento;
        elemento->prox = NULL;
        return;
    }
    //caso seja preciso adicionar no primeiro elemento
    if (elemento->valor < conjunto->head->valor)
    {
        elemento->prox = conjunto->head;
        conjunto->head = elemento;
        return;
    }
    //caso seja preciso adicionar no meio da lista
    Node *tmp2 = conjunto->head;
    while (tmp2->prox != NULL)
    {
        if(tmp2->valor < elemento->valor && elemento->valor < tmp2->prox->valor)
        {
            elemento->prox = tmp2->prox;
            tmp2->prox = elemento;
            return;
        }
        tmp2 = tmp2->prox;
    }
    //caso seja preciso adicionar no final da lista
    tmp2->prox = elemento;
    elemento->prox = NULL;
}

void remover_elemento(CONJUNTO *conjunto,int inteiro)
{
    if (conjunto->head == NULL)
    {
        printf("CONJUNTO VAZIO\n");
        return;
    }
    //caso precise remover elemento no head
    if (conjunto->head->valor == inteiro)
    {
        Node *Aux = conjunto->head;
        conjunto->head = conjunto->head->prox;
        free(Aux);
        return;
    }
    for(Node *tmp = conjunto->head;tmp->prox != NULL;tmp = tmp->prox)
    {
        if (tmp->prox->valor == inteiro)
        {
            Node *Aux = tmp->prox;
            tmp->prox = Aux->prox;
            free(Aux);
            return;
        }
    }
    return;
}
void conjunto_uniao(CONJUNTO* conjunto1,CONJUNTO *conjunto2,CONJUNTO *conjunto3)
{
    if (conjunto1->head != NULL)
    {
        Node *tmp1 = conjunto1->head; 
        while(tmp1 != NULL)
        {
            inserir_elemento(conjunto3,tmp1->valor);
            tmp1 = tmp1->prox;
        }
    }
    if (conjunto2->head != NULL)
    {
        Node *tmp2 = conjunto2->head; 
        while(tmp2 != NULL)
        {
            inserir_elemento(conjunto3,tmp2->valor);
            tmp2 = tmp2->prox;
        }
    }
}
void conjunto_interseccao(CONJUNTO *conjunto1,CONJUNTO *conjunto2,CONJUNTO *conjunto3)
{
    if(conjunto1->head == NULL || conjunto2->head == NULL) 
    {
        return;
    }
    Node *tmp1 = conjunto1->head, *tmp2 = conjunto2->head;
    while (1) 
    {
        if (tmp1 == NULL || tmp2 == NULL) break;
        if (tmp1->valor == tmp2->valor)
        {
            inserir_elemento(conjunto3,tmp1->valor);
            tmp1 = tmp1->prox;
            tmp2 = tmp2->prox;
        }
        else if (tmp1->valor > tmp2->valor) tmp2 = tmp2->prox;
        else if (tmp2->valor > tmp1->valor) tmp1 = tmp1->prox;
    }
    return;
}
void diferenca_de_conjuntos(CONJUNTO *conjunto1,CONJUNTO *conjunto2, CONJUNTO *conjunto3)
{

    if(conjunto1->head != NULL)
    {
        for(Node *tmp1 = conjunto1->head;tmp1 != NULL; tmp1 = tmp1 = tmp1->prox)
        {
            inserir_elemento(conjunto3,tmp1->valor);
        }
    }
    if (conjunto2->head != NULL)
    {
        for(Node *tmp2 = conjunto2->head;tmp2 != NULL; tmp2 = tmp2 = tmp2->prox)
        {
            remover_elemento(conjunto3,tmp2->valor);
        }
    }
}
int menor_elemento(CONJUNTO *conjunto)
{
    if (conjunto->head == NULL)
    {
        printf("Conjnto vazio!\n");
        exit(1);
    }
    return conjunto->head->valor;
}
int maior_elemento(CONJUNTO *conjunto)
{
    if (conjunto->head == NULL)
    {
        printf("Conjnto vazio!\n");
        exit(1);
    }
    Node* tmp = conjunto->head;
    while(tmp->prox != NULL)
    {
        tmp = tmp->prox;
    }
    return tmp->valor;
}
int sao_iguais(CONJUNTO *conjunto1,CONJUNTO *conjunto2)
{
    Node* tmp1 = conjunto1->head;
    Node* tmp2 = conjunto2->head;
    while(tmp1 != NULL && tmp2 != NULL)
    {
        if (tmp1->valor != tmp2->valor)
            return 0;

        tmp1 = tmp1->prox;
        tmp2 = tmp2->prox;
    }

    if (tmp1 != NULL || tmp2 != NULL)
        return 0;
    return 1;
}
void destruir_conjunto(CONJUNTO *conjunto)
{
    if (conjunto->head == NULL) 
    {
        free(conjunto);
        return;
    }
    Node* tmp = conjunto->head,*Aux;
    while (1)
    {
        if (tmp == NULL) break;
        Aux = tmp->prox;
        free(tmp);
        tmp = Aux;
    }
    free(conjunto);
    return;
}
void exibir_conjunto(CONJUNTO *conjunto)
{
    if(conjunto->head == NULL) 
    {
        printf("CONJUNTO VAZIO!"); 
        return;
    }
    Node *tmp = conjunto->head;
    printf("\n(");
    for (;tmp != NULL;tmp = tmp->prox)
    {
        printf(" %d ",tmp->valor);
    }
    printf(")\n");
}
int pertence(CONJUNTO *conjunto1,int valor)
{
    int check = 0;
    if(conjunto1->head == NULL) return 0;
    Node *tmp1 = conjunto1->head;
    while(1)
    {
        if (tmp1 == NULL) break;
        if (tmp1->valor == valor) check = 1;
        tmp1 = tmp1->prox;
    }
    return check;
}