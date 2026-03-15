#include <stdlib.h>
#include <stdio.h>

typedef struct stNode {
    void* dataptr;
    struct stNode* next;
}Node;

typedef struct stAluno {
    int* id;
    float* cr;
}Aluno;
Node *Head = NULL,*Tail = NULL;
void deletar(Node*);
void remover_aluno();
void remover_node(void*);
void atualizar_aluno();
void atualizar_node(void*);
void criar_aluno();
void criar_node(void*,void*);
void* larger(void* dataptr1,void* dataptr2,int (*ptrToCmpFun)(void*,void*));
int compare_function(void*,void*);
void criar_aluno()
{
    int id;
    float cr;
    printf("entre com o id do aluno: ");
    scanf("%d",&id);
    printf("\n");
    printf("entre com o cr do aluno: ");
    scanf("%f",&cr);
    criar_node(&id,&cr);
}

void criar_node(void*dataPtr1,void*dataPtr2)
{
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->id = (int*)malloc(sizeof(int));
    *(aluno->id) = *(int*)dataPtr1;
    aluno->cr = (float*)malloc(sizeof(float));
    *(aluno->cr) = *(float*)dataPtr2;
    Node* node = (Node*)malloc(sizeof(Node));
    node->dataptr = aluno;
    node->next = NULL;
    //se for o primeiro elemento
    if(Head == NULL && Tail == NULL)
    {
        Head = node;
        Tail = node;
    }
    //se tiver mais de um elemento
    else
    {
        Tail->next = node;
        Tail = node;
    }
}
void remover_aluno()
{
    int id;
    printf("Entre com o id do aluno que dejesa remover: ");
    scanf("%d",&id);
    remover_node(&id);
}
void remover_node(void*dataPtr)
{
    if (Head == NULL) return;
    else
    {
        Node *temp = Head,*Aux;
        Aluno* aluno = (Aluno*) Head->dataptr;
        //se for o primeiro elemento
        if(*(aluno->id) == *(int*)dataPtr)
        {
            Aux = Head;
            Head = Head->next;
            //caso só tenha um elemento
            if(Head == NULL) Tail = NULL;
            deletar(Aux);
            return;
        }
        //se estiver no meio da lista
        while(1)
        {
            if (temp->next == NULL) break;
            aluno = (Aluno*)temp->next->dataptr;
            if(*(aluno->id) == *(int*)dataPtr)
            {
                Aux = temp->next;
                temp->next = temp->next->next;
                //caso seja o ultimo node
                if(temp->next == NULL) Tail = temp;
                deletar(Aux);
                return;
            }
            temp = temp->next;
        }
        return;
    }
}
void atualizar_aluno()
{
    int id;
    printf("Entre com o id do aluno que deseja atualizar: ");
    scanf("%d",&id);
    atualizar_node(&id);
}
void atualizar_node(void* dataPtr)
{
    if (Head == NULL) return;
    Node *temp = Head;
    Aluno* aluno = (Aluno*) Head->dataptr;
    int id;
    float cr;
    //se for o primeiro elemento
    if(*(aluno->id) == *(int*)dataPtr)
    {
        printf("Entre com o novo id: ");
        scanf("%d",&id);
        *(aluno->id) = id;
        printf("Entre com o novo Cr: ");
        scanf("%f",&cr);
        *(aluno->cr) = cr;
        return;
    }

    //se estiver no meio da lista
    while(1)
    {
        if (temp->next == NULL) break;
        aluno = (Aluno*)temp->next->dataptr;
        if(*(aluno->id) == *(int*)dataPtr)
        {
            printf("Entre com o novo id: ");
            scanf("%d",&id);
            *(aluno->id) = id;
            printf("Entre com o novo Cr: ");
            scanf("%f",&cr);
            *(aluno->cr) = cr;
            return;
        }
            temp = temp->next;
        }
        return;
}
void comparar_alunos()
{
    void *dataPtr1 = NULL,*dataPtr2 = NULL;
    int id_1,id_2;
    Node* tmp;
    printf("Entre com o id do primeiro Aluno: ");
    scanf("%d",&id_1);
    printf("\n");
    printf("Entre com o id do segundo aluno: ");
    scanf("%d",&id_2);
    tmp = Head;
    while(tmp != NULL)
    {
        Aluno* aluno = (Aluno*) tmp->dataptr;
        if(*(aluno->id) == id_1) dataPtr1 = aluno;
        else if (*(aluno->id) == id_2) dataPtr2 = aluno;
        tmp = tmp->next;
    }
    if(dataPtr1 == NULL || dataPtr2 == NULL)
    {
        printf("Um id não existe!");
        return;
    }
    Aluno* melhor_aluno = (Aluno*)larger(dataPtr1,dataPtr2,compare_function);
    printf("O aluno de id %d tem o cr maior (%.2f)! ",*melhor_aluno->id,*melhor_aluno->cr);
    
}
void* larger(void* dataptr1,void* dataptr2,int (*ptrToCmpFun)(void*,void*))
{
    return (*ptrToCmpFun)(dataptr1,dataptr2) > 0 ? dataptr1 : dataptr2;
}
int compare_function(void*dataPtr1,void*dataPtr2)
{
    Aluno* aluno_1 = (Aluno*)dataPtr1;
    Aluno* aluno_2 = (Aluno*)dataPtr2;
    return *(aluno_1->cr) > *(aluno_2->cr) ? 1 : -1;
}
void deletar(Node* node)
{
    Aluno* aluno = (Aluno*) node->dataptr;

    free(aluno->id);
    free(aluno->cr);
    free(aluno);
    free(node);
}
void exibir_lista()
{
    if (Head == NULL)
    { 
        printf("Lista vazia!"); 
        return;
    }
    Node* tmp = Head;
    while(getchar() != '\n');
    while(tmp != NULL)
    {
        Aluno* aluno = (Aluno*) tmp->dataptr;
        printf("id: %d  cr: %.2f\n",*aluno->id,*aluno->cr);
        printf("Pressione ENTER para ver o próximo aluno...");
        getchar();
        tmp = tmp->next;
    }
}
