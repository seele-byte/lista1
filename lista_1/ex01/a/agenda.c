#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 40
typedef struct agenda
{
    char nome[MAX_CHARS];
    char email[MAX_CHARS];
    int telefone;
} AGENDA;


void aloca(AGENDA **pAgenda, int *piEntradas);
void consulta(AGENDA *pAgenda, int iEntradas);
void qs_ordena(AGENDA pAgenda[], int left, int right);
void ordena(AGENDA pAgenda[], int iEntradas);
void excluir(AGENDA **pAgenda, int *piEntradas);
void pesquisar(AGENDA *pAgenda, int iEntradas);
void alterar(AGENDA *pAgenda, int iEntradas);

void limpar_enter(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

int main()
{
    AGENDA *pAgenda;
    int iEntradas = 0;
    int op;

    pAgenda = malloc(sizeof(AGENDA));
    if (pAgenda == NULL)
    {
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }

    do
    {
        printf("\n1 - Inclusao");
        printf("\n2 - Alteracao");
        printf("\n3 - Consulta");
        printf("\n4 - Excluir");
        printf("\n5 - Pesquisar");
        printf("\n9 - Sair");
        printf("\nEntre com uma opcao -> ");
        scanf("%d", &op);
        getchar();

        if (op == 1)
        {
            aloca(&pAgenda, &iEntradas);

            printf("\nEntre com o Nome: ");
            fgets(pAgenda[iEntradas].nome, MAX_CHARS, stdin);
            limpar_enter(pAgenda[iEntradas].nome);

            printf("Entre com o email: ");
            fgets(pAgenda[iEntradas].email, MAX_CHARS, stdin);
            limpar_enter(pAgenda[iEntradas].email);

            printf("Entre com o telefone: ");
            scanf("%d", &pAgenda[iEntradas].telefone);
            getchar();

            iEntradas++;
        }

        else if (op == 2)
        {
            alterar(pAgenda, iEntradas);
        }

        else if (op == 3)
        {
            ordena(pAgenda, iEntradas);
            consulta(pAgenda, iEntradas);
        }

        else if (op == 4)
        {
            excluir(&pAgenda, &iEntradas);
            ordena(pAgenda, iEntradas);
        }

        else if (op == 5)
        {
            ordena(pAgenda, iEntradas);
            pesquisar(pAgenda, iEntradas);
        }

    } while (op != 9);

    free(pAgenda);
}

void consulta(AGENDA *pAgenda, int iEntradas)
{
    for (int i = 0; i < iEntradas; i++)
    {
        printf("\n\nRegistro %d", i);
        printf("\nNome: %s", pAgenda[i].nome);
        printf("\nEmail: %s", pAgenda[i].email);
        printf("\nTelefone: %d\n", pAgenda[i].telefone);
        printf("Pressione ENTER...");
        getchar();
    }
}

void alterar(AGENDA *pAgenda, int iEntradas)
{
    char nome[40];
    char op;
    int i = 0;
    printf("\nDigite o Nome: ");
    fgets(nome, MAX_CHARS, stdin);
    limpar_enter(nome);

    for (; i < iEntradas; i++)
    {
        if (strncmp(pAgenda[i].nome, nome, strlen(nome)) == 0)
        {
            printf("\nRegistro encontrado!");
            printf("\n\tRegistro %d", i);
            printf("\n\tNome : %s", pAgenda[i].nome );
            printf("\n\tEmail : %s", pAgenda[i].email );
            printf("\n\tFone : %d", pAgenda[i].telefone );
            printf("\n\tConirma a alteracao ?(s/n)");
            scanf(" %c",&op);
            if( op == 'S' || op == 's' )
            {
                printf("\nNovo nome: ");
                fgets(pAgenda[i].nome, MAX_CHARS, stdin);
                limpar_enter(pAgenda[i].nome);
                printf("Novo email: ");
                fgets(pAgenda[i].email, MAX_CHARS, stdin);
                limpar_enter(pAgenda[i].email);
                printf("Novo telefone: ");
                scanf("%d", &pAgenda[i].telefone);
                return;
            }
            else
            {
                continue;
            }
        }    
    }
    if (i >= iEntradas)
    {
        printf("Registro não encontrado");
    }
}

void excluir(AGENDA **pAgenda, int *piEntradas)
{
    char nome[MAX_CHARS];

    printf("\nDigite o Nome: ");
    fgets(nome, MAX_CHARS, stdin);
    limpar_enter(nome);

    for (int i = 0; i < *piEntradas; i++)
    {
        if (strncmp((*pAgenda)[i].nome, nome, strlen(nome)) == 0)
        {
            (*piEntradas)--;
            (*pAgenda)[i] = (*pAgenda)[(*piEntradas)];
            *pAgenda = realloc(*pAgenda, (*piEntradas) * sizeof(AGENDA));

            printf("\nRegistro excluido\n");
            return;
        }
    }
    printf("\nRegistro nao encontrado\n");
}

void pesquisar(AGENDA *pAgenda, int iEntradas)
{
    char nome[MAX_CHARS];

    printf("\nDigite o Nome: ");
    fgets(nome, 40, stdin);
    limpar_enter(nome);

    for (int i = 0; i < iEntradas; i++)
    {
        if (strncmp(pAgenda[i].nome, nome, strlen(nome)) == 0)
        {
            printf("\nNome: %s", pAgenda[i].nome);
            printf("\nEmail: %s", pAgenda[i].email);
            printf("\nTelefone: %d\n", pAgenda[i].telefone);
            return;
        }
    }

    printf("\nRegistro nao encontrado\n");
}

void ordena(AGENDA pAgenda[], int iEntradas)
{
    if (iEntradas > 0)
        qs_ordena(pAgenda, 0, iEntradas - 1);
}

void qs_ordena(AGENDA pAgenda[], int left, int right)
{
    int i = left;
    int j = right;
    char *x = pAgenda[(left + right) / 2].nome;
    AGENDA t;

    do
    {
        while (strcmp(pAgenda[i].nome, x) < 0 && i < right)
            i++;

        while (strcmp(pAgenda[j].nome, x) > 0 && j > left)
            j--;

        if (i <= j)
        {
            t = pAgenda[i];
            pAgenda[i] = pAgenda[j];
            pAgenda[j] = t;
            i++;
            j--;
        }

    } while (i <= j);

    if (left < j)
        qs_ordena(pAgenda, left, j);

    if (i < right)
        qs_ordena(pAgenda, i, right);
}

void aloca(AGENDA **pAgenda, int *piEntradas)
{
    *pAgenda = realloc(*pAgenda, (*piEntradas + 1) * sizeof(AGENDA));

    if (*pAgenda == NULL)
    {
        printf("Erro de realocacao\n");
        exit(1);
    }
}