#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h> 

#define MAX_EXT_LENGTH 10 //comprimento máximo para o arg. de -e

void listDir(char dirname[], char mode[]) { // listDir(/some/directory, "-f")
    DIR *dp;
    struct dirent *dent;
    int print_dir, print_file;              // flags que dizem se é para printar dirs e/ou files
    char *ext = (char *) malloc(strlen(mode) * sizeof(char));   //sizeof(char) == 1, é apenas para a lógica

    if (strcmp(mode, "-d") == 0) {      //mode: directories
        print_dir = 1;
        print_file = 0;
    }
    else if (strcmp(mode, "-f") == 0) { //mode: files
        print_dir = 0;
        print_file = 1;
    }
    else if (strcmp(mode, "") != 0) {   //mode: files with extension "ext"
        print_file = 1;
        print_dir = 0;
        strcpy(ext, mode);
    }
    else {                              //mode: everything
        print_dir = 1;
        print_file = 1;
    }

    dp = opendir(dirname);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    dent = readdir(dp);
    while (dent != NULL) {
        if (dent->d_name[0] != '.') {      //do not list hidden dirs/files
            if (dent->d_type == DT_DIR) {  //se for directory
                if (print_dir) {           //se for para printar directories
                    char path[200];
                    strcpy(path, ""); // inicializar direito     //Copyright Lucius Vinicius 2020
                    strcat(path, dirname);
                    strcat(path, "/");
                    strcat(path, dent->d_name);
                    printf("d %s/%s\n", dirname, dent->d_name);
                }
            }
            else if (print_file) {                                      //se for para printar files
                if (ext[0] == '\0') {                                       //se não houver filtro de extensão (ext vazia)
                    printf("  %s/%s\n", dirname, dent->d_name);             //printar
                }
                else {                                                      //se houver filtro de extensão
                    char *d_ext = strrchr(dent->d_name, '.');               //d_ext = extensão do ficheiro com prefixo '.'
                    if (d_ext != NULL) {                                    //se tiver extensão    
                        if (strcmp(++d_ext, ext) == 0) {                    //incrementa-se o ponteiro d_ext para remover o 1º char ('.')
                            printf("  %s/%s\n", dirname, dent->d_name);     //printar se d_ext for igual a ext após o incremento
                        }                      
                    }
                }
            }
        }
        dent = readdir(dp);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Must input at least 1 directory as an argument.\n");
    }

    struct option long_options[] = {
    //  {char *name, int has_arg, int *flag, int val}
        {"file", no_argument,       NULL, 'f'},     //utilizado apenas para converter
        {"dir",  no_argument,       NULL, 'd'},     //as long opts em opts normais
        {"ext",  required_argument, NULL, 'e'},
    };

    int opts_used = 0;  //número de opções usadas
    char *opt_chosen = (char *) malloc(MAX_EXT_LENGTH * sizeof(char));  //para guardar a opção argumento de listDir
    int opt;
    while ((opt = getopt_long(argc, argv, "fde:", long_options, NULL)) != -1) {  //processar opções
        switch (opt) {
            case 'f':
                strcpy(opt_chosen, "-f");
                opts_used++;
                break;
            case 'd':
                strcpy(opt_chosen, "-d");
                opts_used++;
                break;
            case 'e':
                strcpy(opt_chosen, optarg);
                opts_used++;
                break;
            default:
                printf("Invalid option.\n");
                return EXIT_FAILURE;
        }
    }

    if (opts_used > 1) { //não é suposto serem introduzidas várias opções
        printf("Must input at most one option.\n");
        return EXIT_FAILURE;
    }

    //getopt mete as non-options no fim, logo vão começar em optind e acabar em argc
    for (int i = optind; i < argc; i++) {   //para cada dir introduzido
       listDir(argv[i], opt_chosen);        //correr a função listDir
    }

    return EXIT_SUCCESS;
}