#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ordenar alfabeticamento todos os argumentos recebidos que comecem por uma letra
// ordenacao crescente ou decrescente, variavel de ambiente -> SORTORDER
// ignorar a diferenca entre letras maiusculas e minusculas

int main(int argc, char *argv[]){

    int i, j, value;
    char copy[100];

    char *sortorder = getenv("SORTORDER");

    if (sortorder == NULL){
        printf("ERRO: não exite uma variável de ambiente\n");
        return EXIT_FAILURE;
    }

    if(strcmp(sortorder,"0") == 0){
        printf("Sort por ordem crescente(a-z)\n");
        for(i = 1; i < argc-1; i++){
            //printf("hello test%i\n",i);
            for (j = i+1; j < argc; j++){
                printf("argvi: %s\n",argv[i]);
                value = strcmp(argv[i],argv[j]);
                printf("i: %s, j: %s, valor: %i\n",argv[i],argv[j],value);
                if(value>0){
                    //strcpy(copy,argv[i]);
                    //printf("copia: %s\n",copy);
                    //strcpy(argv[i],argv[j]);
                    //printf("argviif: %s\n",argv[i]);
                    //strcpy(argv[j],copy);
                }
            }
        }
    }

    for (i = 1; i < argc; i ++){
        printf("%s\n", argv[i]);
    }

    return EXIT_SUCCESS;
}