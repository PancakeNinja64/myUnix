#ifndef PARSER_H
#define PARSER_H

#define MAX_TOKENS 128

typedef struct {
    char *argv[MAX_TOKENS]; //NULL-terminated argv
    char *infile;
    char *outfile;
    int append;
    int background;
} command_t;

int parse_lin(char *line, command_t*cmd);

#endif