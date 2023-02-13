#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man system
 man date
*/

int main(int argc, char *argv[])
{
    char text[1024];
    FILE *command_log;
    
    do
    {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        /* system(const char *command) executes a command specified in command
            by calling /bin/sh -c command, and returns after the command has been
            completed.
        */

        if(strcmp(text, "end")) {
           printf("\n * Command to be executed: %s\n", text);
           printf("---------------------------------\n");
           time_t current_time = time(NULL);
           char *time_string = ctime(&current_time); 
           system(text);
           command_log = fopen("command_log", "a");
           fprintf(command_log, "%s %s\n", time_string, text);
           printf("---------------------------------\n");
        }
    } while(strcmp(text, "end"));

    printf("-----------The End---------------\n");
    fclose(command_log);
    return EXIT_SUCCESS;
}