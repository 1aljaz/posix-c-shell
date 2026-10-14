#ifndef PARSER_H
#define PARSER_H

#define in_buffer_limit 1024
#define parsed_buffer_limit 64
#define parsed_word_length_limit 64

char* sh_read_line();
char** sh_parse_line(char*);

#endif