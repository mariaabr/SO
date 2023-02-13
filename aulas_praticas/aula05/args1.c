#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    if(argc <= 3){
        for(i = 0 ; i < argc ; i++)
        {
            printf("Argument %02d: \"%s\"\n", i, argv[i]);        
        }
    }else{
        printf("Introduza no máximo 2 argumentos\n");
        return EXIT_FAILURE; // echo $? == 1
    }

    return EXIT_SUCCESS; // echo $? == 0
}