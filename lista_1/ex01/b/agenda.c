#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#define MAX_CHARS 40

typedef struct contato {
    char nome[MAX_CHARS];
    char email[MAX_CHARS];
    int telefone;
}CONTATO;

typedef struct agenda
{
    CONTATO  *contatos;
    int tamanho;

} AGENDA;

AGENDA* criar_agenda(){
    AGENDA* agenda =  (AGENDA*) malloc(sizeof(AGENDA));
    if (agenda == NULL){
        printf("Erro de memória\n");
        exit(1);
    }
    return agenda;
}
void liberar_agenda(AGENDA *agenda)
{
    free(agenda);
}
void limpar_enter(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}
void inclusao(AGENDA *Agenda){
    Agenda->contatos = realloc(Agenda->contatos, (Agenda->tamanho + 1) * sizeof(CONTATO));
    if (Agenda->contatos == NULL)
    {
        printf("Erro de realocacao\n");
        exit(1);
    }
    printf("\nEntre com o Nome: ");
    fgets(Agenda->contatos[Agenda->tamanho].nome, MAX_CHARS, stdin);
    limpar_enter(Agenda->contatos[Agenda->tamanho].nome);
    printf("Entre com o email: ");
    fgets(Agenda->contatos[Agenda->tamanho].email, MAX_CHARS, stdin);
    limpar_enter(Agenda->contatos[Agenda->tamanho].email);
    printf("Entre com o telefone: ");
    scanf("%d", &Agenda->contatos[Agenda->tamanho].telefone);
    getchar();
    Agenda->tamanho ++;
}

void consulta(AGENDA *Agenda){
    ordena(Agenda);
    for (int i = 0; i < Agenda->tamanho; i++)
    {
        printf("\n\nRegistro %d", i);
        printf("\nNome: %s", Agenda->contatos[i].nome);
        printf("\nEmail: %s", Agenda->contatos[i].email);
        printf("\nTelefone: %d\n", Agenda->contatos[i].telefone);
        printf("Pressione ENTER...");
        getchar();
    }
}

void ordena(AGENDA *agenda)
{
    for (int i = 0; i < agenda->tamanho - 1; i++)
    {
        for (int j = 0; j < agenda->tamanho - i - 1; j++)
        {
            if (strlen(agenda->contatos[j].nome) >
                strlen(agenda->contatos[j + 1].nome))
            {
                CONTATO temp = agenda->contatos[j];
                agenda->contatos[j] = agenda->contatos[j + 1];
                agenda->contatos[j + 1] = temp;
            }
        }
    }
}

void excluir(AGENDA* Agenda){
    char nome[MAX_CHARS];

    printf("\nDigite o Nome: ");
    fgets(nome, MAX_CHARS, stdin);
    limpar_enter(nome);
    for (int i = 0; i < Agenda->tamanho; i++)
    {
        if (strncmp(Agenda->contatos[i].nome, nome, strlen(nome)) == 0)
        {
            printf("\nRegistro encontrado!");
            printf("\n\tRegistro %d", i);
            printf("\n\tNome : %s", Agenda->contatos[i].nome);
            printf("\n\tEmail : %s", Agenda->contatos[i].email);
            printf("\n\tFone : %d", Agenda->contatos[i].telefone);
            Agenda->tamanho --;
            Agenda->contatos[i] = Agenda->contatos[Agenda->tamanho];
            Agenda->contatos = realloc(Agenda->contatos,Agenda->tamanho * sizeof(CONTATO));
            printf("\nRegistro excluido\n");
            ordena(Agenda);
            return;
        }
    }
    printf("\nRegistro nao encontrado\n");
}

void pesquisar(AGENDA *Agenda)
{
    char nome[MAX_CHARS];

    printf("\nDigite o Nome: ");
    fgets(nome, MAX_CHARS, stdin);
    limpar_enter(nome);

    for (int i = 0; i < Agenda->tamanho; i++)
    {
        if (strncmp(Agenda->contatos[i].nome, nome, strlen(nome)) == 0)
        {
            printf("\nNome: %s", Agenda->contatos[i].nome);
            printf("\nEmail: %s", Agenda->contatos[i].email);
            printf("\nTelefone: %d\n", Agenda->contatos[i].telefone);
            return;
        }
    }

    printf("\nRegistro nao encontrado\n");
}

void alterar(AGENDA *Agenda)
{
    char nome[40];
    char op;
    int i = 0;
    printf("\nDigite o Nome: ");
    fgets(nome, MAX_CHARS, stdin);
    limpar_enter(nome);

    for (; i < Agenda->tamanho; i++)
    {
        if (strncmp(Agenda->contatos[i].nome, nome, strlen(nome)) == 0)
        {
            printf("\nRegistro encontrado!");
            printf("\n\tRegistro %d", i);
            printf("\n\tNome : %s", Agenda->contatos[i].nome);
            printf("\n\tEmail : %s", Agenda->contatos[i].email);
            printf("\n\tFone : %d", Agenda->contatos[i].telefone);
            printf("\n\tConirma a alteracao ?(s/n)");
            scanf(" %c",&op);
            if( op == 'S' || op == 's' )
            {
                printf("\nNovo nome: ");
                fgets(Agenda->contatos[i].nome, MAX_CHARS, stdin);
                limpar_enter(Agenda->contatos[i].nome);
                printf("Novo email: ");
                fgets(Agenda->contatos[i].email, MAX_CHARS, stdin);
                limpar_enter(Agenda->contatos[i].email);
                printf("Novo telefone: ");
                scanf("%d", &Agenda->contatos[i].telefone);
                return;
            }
            else
            {
                continue;
            }
        }    
    }
    if (i >= Agenda->tamanho)
    {
        printf("Registro não encontrado");
    }
}