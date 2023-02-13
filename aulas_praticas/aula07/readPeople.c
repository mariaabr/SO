#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %9s, %5d, %9f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p;
    Person info[100] = {
        {.age = -1},
        {.name = "N/A"},
        {.height = 0}
    };
    
    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    // printf("-------- Nome   Idade Altura ---------\n");
    // while(fread(&p, sizeof(Person), 1, fp) == 1)
    // {

    //     printPersonInfo(&p);
    // }

    int n = 0;
    printf("------------ %4s  %5s  %7s ------------\n", "Nome", "Idade", "Altura");
    while (fread(&p, sizeof(Person), 1, fp) == 1 && n < 100) {
        printPersonInfo(&p);
        info[n++] = p;
    }

    //fclose(fp);

    //adicionar mais pessoas
    char add_people;
    printf("Add people? (y/n): ");
    scanf(" %c", &add_people);

    if (add_people == 'y') {
        fp = fopen(argv[1], "ab"); //abrir para dar append
        int n2;
        printf("Enter number of people to add: ");
        scanf(" %d", &n2);

        if (n2 + n > 100) {
            printf("Maximum number of people (%d) would be exceeded (current amount: %d).\n", 100, n);
            return EXIT_FAILURE;
        }

        char name[64];
        int age;
        double height;

        for (int i = 0; i < n2; i++) {
            //printf("cucu");
            printf("-> Adding person %d\n", i+1);
            printf("Enter name: ");
            scanf(" %[^\n]", name);    //poder escrever nomes com espaços
            printf("Enter age: ");
            scanf(" %d", &age);
            printf("Enter height (m): ");
            scanf(" %lf", &height);
            strcpy(p.name, name);
            p.age = age;
            p.height = height;
            fwrite(&p, sizeof(Person), 1, fp);
        }

        // int num = 0;
        // printf("------------ %4s  %5s  %7s ------------\n", "Nome", "Idade", "Altura");
        
        // while (fread(&p, sizeof(Person), 1, fp) == 0 && num < 100) {
        // printPersonInfo(&p);
        // info[num++] = p;
        // }

        fclose(fp);
    }

    return EXIT_SUCCESS;
}