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
}