#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "execute.h"

int main(){
    printf("> ");
    
    char* line = sh_read_line();
    char** parsed_line = sh_parse_line(line);

    if (parsed_line[0] == NULL){
        free(parsed_line);
        free(line);
        return -1;
    }

    int status = execute_command(parsed_line);
    
    for(int i = 0; parsed_line[i] != NULL;i++){
        free(parsed_line[i]);
    }
    free(parsed_line);
    free(line);
}