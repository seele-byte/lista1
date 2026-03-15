#ifndef AGENDA_H
#define AGENDA_H
typedef struct agenda AGENDA;
AGENDA* criar_agenda();
//cria uma AGENDA
void liberar_agenda(AGENDA *Agenda);
//Fecha a AGENDA
void inclusao(AGENDA *Agenda);
//aumenta a agenda para por mais um registro
void consulta(AGENDA *pAgenda);
//mostra todos registros na AGENDA
void ordena(AGENDA *Agenda);
//ordena os elementos na AGENDA em ordem crescente pelo numero de letras no nome
void excluir(AGENDA *Agenda);
//deleta um registro da AGENDA
void pesquisar(AGENDA *Agenda);
//verifica se um nome está na AGENDA
void alterar(AGENDA *Agenda);
//modifica um registro na AGENDA
#endif