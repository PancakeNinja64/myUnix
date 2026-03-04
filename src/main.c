#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "executor.h"
#include <signal.h>

int main(void){
    char *line = NULL;
    size_t len = 0;

    //signal handling: ignore SIGINT in shell
    struct sigaction sa;
    sas.sa_hangler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        printf("myUnix> ");
        fflush(stdout);
        ssize_t n = getline(&line, &len, stdin);
        if (n == -1) { //EOF (CRTL+D)
            printf("\n");
            break;
        }
        //skip empty
        if (n == 1) continue;

        command_t cmd;
        parse_line(line, &cmd);
        execute_command(&cmd);

        //free strdup'd fields in parse_line 
        for (int i=0; cmd.argv[i]; i++) free(cmd.argv[i]);
        if (cmd.infile) free(cmd.infile);
        if (cmd.oufile) free(cmd.outfile);
    }
    free(line);
    return 0;
}
