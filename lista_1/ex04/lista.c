#include <stdlib.h>
#include <stdio.h>
#define MAX_ALUNOS 20
typedef struct aluno 
{
    float CR;
    int id;
}ALUNO;

typedef struct node
{
    ALUNO* aluno;
    struct node* link;
} NODE;
NODE *head = NULL;
NODE *tail = NULL;
NODE* criar_node()
{
    NODE* node = (NODE*) malloc(sizeof(NODE));
    return node;

}
void adicionar_aluno(int id,float cr)
{
    ALUNO* aluno = criar_aluno(id,cr);
    NODE* node = criar_node();
    node->aluno = aluno;
    node->link = NULL;
    //caso seja o primeiro elemento
    if(head == NULL && tail == NULL)
    {
        head = node;
        tail = node;
    }
    //caso tenha apenas um elemento
    else if(head == tail)
    {
        tail = node;
        head->link = node;
    }
    //caso ja tenha mais de um elemento
    else 
    {
        tail->link = node;
        tail = node;
    }
    return;
}
ALUNO* criar_aluno(int id,float cr)
{
    ALUNO* aluno = (ALUNO*) malloc(sizeof(ALUNO));
    aluno->CR = cr;
    aluno->id = id;
    return aluno;
}
void* larger (void* dataPtr1, void* dataPtr2,int (*ptrToCmpFun)(void*, void*))
    {
        if ((*ptrToCmpFun) (dataPtr1, dataPtr2) > 0)
            return dataPtr1;
    else
    return dataPtr2;
} 
int comparar(ALUNO* aluno1,ALUNO* aluno2)
{
    if (aluno1->CR > aluno2->CR)
        return 1;
    else
        return 0;
}
void melhor_aluno(aluno)