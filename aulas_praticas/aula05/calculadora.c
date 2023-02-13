#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int i;
    double n1, n2;
    char op;
    char *endarg;
    double result = 0;

    if(argc <= 4){
        for(i = 0 ; i < argc ; i++)
        {
            printf("Argument %02d: \"%s\"\n", i, argv[i]);        
        }

    n1 = atof(argv[1]);
    n2 = atof(argv[3]);
    op = *(argv[2]);

    n1 = strtod(argv[1],&endarg);
    if (endarg == argv[1] || *endarg != '\0')
    // arg vazio ou nao estritamente numerico
    {
        printf("1º argumento inválido: indique n1\toperação[+,-,x,/,p]\tn2\n");
        return EXIT_FAILURE;
    }
    n2 = strtod(argv[3],&endarg);
    if (endarg == argv[3] || *endarg != '\0')
    // arg nao numerico ou nao estritamente numerico
    {
        printf("2º argumento inválido: indique n1\toperação[+,-,x,/,p]\tn2\n");
        return EXIT_FAILURE;
    }

        switch(op){
            case '+':
                result = n1 + n2;
                printf("%.1f + %.1f = %.1f\n", n1, n2,  result);
                break;
            case '-':
                result = n1 - n2;
                printf("%.1f - %.1f = %.1f\n", n1, n2,  result);
                break;
            case 'x':
                result = n1 * n2;
                printf("%.1f * %.1f = %.1f\n", n1, n2,  result);
                break;
            case '/':
                result = n1 / n2;
                printf("%.1f +/ %.1f = %.1f\n", n1, n2,  result);
                break;
            case 'p':
                result = pow(n1,n2);
                printf("%.1f p %.1f = %.1f\n", n1, n2,  result);
                break;
        }
    }else{
        printf("Introduza no máximo 3 argumentos\n");
        return EXIT_FAILURE; // echo $? == 1
    }

    return EXIT_SUCCESS; // echo $? == 0
}


//alinea e)
/* Como * e reconhecido pela Bash (lista todos os documentos da diretoria atual, ao colocar mos * nao
teriamos 1 argumento, mas sim um numero de argumentos igual ao numero de ficheiros na diretoria atual)!*/

