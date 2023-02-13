#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv){
    int count = 0;
    int min = atoi(argv[1]); //atoi -> converte para número inteiro
    int max = atoi(argv[2]);
    int secreto = min + rand() % (max+1 - min); // max+1 para incluir o numero max no range de gerar valores random
    int reply = 0;

    if( argc != 3){
        printf("Introduza apenas o valor máximo e mínimo\n");

        return EXIT_FAILURE;
    }else{
        printf("Tenta adivinhar o número secreto que nós temos para ti, min=%d e max=%d:\n", min, max);
        while (reply != secreto){
            scanf("%d", &reply);
            if(reply < secreto){
                printf("essa foi boa mas foi baixinha...\n");
                count ++;
            } else if(reply > secreto){
                printf("a tua resposta foi mais alta do que o suposto\n");
                count ++;
            }else{
                printf("Parabéns, conseguiste acertar no número secreto!!\n");
                printf("Acertaste em %d tentativas :))\n", count);
            }
        }
    }

    return EXIT_SUCCESS;
}