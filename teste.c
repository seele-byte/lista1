#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void buscasub(char *str, char*sub, int index_original){

    int sub_len = strlen(sub);
    int str_len = strlen(str);

    if (str_len < sub_len){
        return;
    }

    if (strncmp(str, sub, sub_len) == 0){
        printf("Substring encontrada no index %d \n", index_original);
    }

    buscasub(str + 1, sub, index_original + 1);

}








int main()
{
   char str_cpt[] = "banana";
   char str_sub[] = "ana";

   printf("Buscando '%s' em '%s':", str_sub, str_cpt);

    buscasub(str_cpt, str_sub, 0);


    }
