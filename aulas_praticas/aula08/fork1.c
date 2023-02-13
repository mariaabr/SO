#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int ret;
    char my_role[10];

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid()); // PID -> filho, PPID -> pai
    if ((ret = fork()) < 0) { 
        perror ("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0){
        sleep (1);
        strcpy(my_role,"PAI");
    }else{
        strcpy(my_role,"FILHO");
    }
    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, Eu sou o %s\n", getpid(), getppid(), my_role);
    // ou
    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, Eu sou o %s\n", getpid(), getppid(), ret == 0 ? "Filho":"Pai");


    return EXIT_SUCCESS;
}