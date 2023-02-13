#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i, numChars;
    char **sent = argv;
    //printf("%s\n", argv[3]);
    //printf("%s\n",sent[3]);
    numChars = 0;
    for(i = 1 ; i < argc ; i++)
    {
        numChars += strlen(argv[i]);
        if(i != argc-1){
            printf("%s ",sent[i]);
        }else{
            printf("%s\n",sent[i]);
        }
    }

    printf("All arguments have %d characters\n", numChars);

    return EXIT_SUCCESS;
}