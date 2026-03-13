#include <stdlib.h>
#include <stdio.h>
#include "agenda.h"
#define MAX_CHARS 40

int main()
{
    int op;

    AGENDA* Agenda = criar_agenda();
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
            inclusao(Agenda);
        }

        else if (op == 2)
        {
            alterar(Agenda);
        }

        else if (op == 3)
        {
            consulta(Agenda);
        }

        else if (op == 4)
        {
            excluir(Agenda);
        }

        else if (op == 5)
        {
            pesquisar(Agenda);
        }

    } while (op != 9);

    liberar_agenda(Agenda);
}