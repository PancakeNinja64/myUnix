#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int parse_line(char *line, command_t *cmd) {
    for(int i = 0; i < MAX_TOKENS; i++){cmd->argv[i]=NULL; }
    cmd->infile = NULL;
    cmd->outfile = NULL;
    cmd->append = 0;
    cmd->background = 0;

    char *tok;
    int argc = 0;
    tok = strtok(line, " \t\r\n");
    while (tok != NULL && argc < MAX_TOKENS-1) {
        if (strcmp(tok, "<") == 0) {
            tok = strtok(NULL, " \t\r\n");
            if (tok) cmd ->infile = strdup(tok);
        }
    }
}