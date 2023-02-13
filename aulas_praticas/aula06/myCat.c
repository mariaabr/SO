#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 1000 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 

    /* Validate number of arguments */
    if( argc > 4 )
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* Open the file provided as argument */
    errno = 0;
    
    for(int i = 1; i < argc; i++){
        fp = fopen(argv[i], "r");
        if( fp == NULL )
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        int count = 1;
        /* Read all the lines of the file */
        while( fgets(line, sizeof(line), fp) != NULL )
        {
            printf("%i -> %s", count, line); /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
            count++;
        }
        count = 1; //sem este count conta o numero de linhas totais dos 3 ficheiros juntos

        printf("------------------------------");
        printf("\n");
    }
    fclose(fp);

    return EXIT_SUCCESS;
}