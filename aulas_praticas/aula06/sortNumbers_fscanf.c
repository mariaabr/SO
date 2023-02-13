#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}


#define LINEMAXSIZE 500
int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line[LINEMAXSIZE];

    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if( fp == NULL )
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    int lineNumber = 1;
    int val = 0;

    while(fscanf(fp, "%d",&val) == 1){
        lineNumber++;
    }

    int nums[lineNumber-1];
    
    lineNumber = 1;
    fp = fopen(argv[1], "r");
    printf("Unsorted numbers: \n");
    while(fscanf(fp, "%d",&val) == 1){
        nums[lineNumber-1] = val;
        printf("%d\n", val);
        lineNumber++;
    }

    fclose(fp);

    int numSize = sizeof(nums)/sizeof(nums[0]);

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
    The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(nums, numSize, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for(int i = 0 ; i < numSize ; i++){
        printf("%d\n", nums[i]);
    }

    return EXIT_SUCCESS;
}