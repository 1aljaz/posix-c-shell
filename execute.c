#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int execute_command(char** args){
    if (args[0] == NULL) return 1;

    pid_t pid = fork();

    if (pid == 0){
        if (execvp(args[0], args) == -1){
            perror("Napaka pri ukazu");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0){
        perror("Napaka pri forku");
    } else {
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
        
    }
    printf("> ");
    return 1;
}