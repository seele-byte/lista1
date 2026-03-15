#include <stdio.h>
#include "lista.h"

int main()
{
    int opcao;

    while(1)
    {
        printf("1 - Adicionar aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Atualizar aluno\n");
        printf("4 - Comparar alunos\n");
        printf("5 - Exibir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                criar_aluno();
                break;

            case 2:
                remover_aluno();
                break;

            case 3:
                atualizar_aluno();
                break;

            case 4:
                comparar_alunos();
                break;

            case 5:
                exibir_lista();
                break;

            case 0:
                printf("Encerrando programa...\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}

