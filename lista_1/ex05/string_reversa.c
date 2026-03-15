#include <stdlib.h>
#include <stdio.h>

void mostrar_ao_contrario(char*,int);
int main()
{
    char string[] = "A roxy eh a melhor de todas";
    mostrar_ao_contrario(string,0);
}
void mostrar_ao_contrario(char *string,int i)
{
    if(string[i] == '\0') return;
    mostrar_ao_contrario(string,i+1);
    printf("%c",string[i]);
}