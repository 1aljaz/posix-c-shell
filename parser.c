#include <stdio.h>
#include <stdlib.h>

#define in_buffer_limit 1024
#define parsed_buffer_limit 64
#define parsed_word_length_limit 64

char* sh_read_line(){
    int c;
    char* line = malloc(in_buffer_limit);
    int curr = 0;
    int buffer = in_buffer_limit;

    while(1){
        c = getchar();
        if ((c == EOF) || (c == '\n')){
            line[curr] = '\0';
            return line;
        }

        if (curr + 1 >= buffer){
            buffer *= 2;
            line = realloc(line, buffer);
        }
        line[curr++] = c;
    }
}

char** sh_parse_line(char* line){
    char** parsed_line = malloc(parsed_buffer_limit*sizeof(char*));
    int words = 0;
    char* p = line;

    while(*p != '\0'){
        while (*p == ' ') p++;
        if (*p == '\0') break;

        parsed_line[words] = malloc(parsed_word_length_limit + 1);
        int i = 0;

        while(*p != ' ' && *p != '\0'){
            parsed_line[words][i++] = *p;
            p++;
        }

        parsed_line[words][i] = '\0';
        words++;
    }
    parsed_line[words] = NULL;
    return parsed_line;
}