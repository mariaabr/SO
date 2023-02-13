#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){
    int i;
    char **sent = argv;

    for (i = 0; i < argc; i++){
        if(isalpha(argv[i][0])){
            if( i != argc -1){
                printf("%s ",sent[i]);
            }else{
                printf("%s\n",sent[i]);
            }
        }
    }
    
    return EXIT_SUCCESS;
}