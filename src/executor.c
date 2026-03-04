#include "executor.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int execute_command(command_t *cmd) {
    if (!cmd->[0]) return 0;

    //exit
    if (strcmp(cmd->argv[0], "exit") == 0) {
        exit(0);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        //Child: redirection handling
        if (cmd->infile){
            int fd = open(cmd->infile, O_RDONLY);
            if (fd < 0) { perror("open infile"); exit(1); }
            dup2(fd, STDIN_FILENO);
            close(fd);
        }
        if (cmd->outfile){
            int flags = O_WRONGLY | O_CREAT | (cmd->append ? O_APPEND : O_TRUNC);
            int fd = open(cmd->outfile,flags, 0644);
            if (fd < 0) { perror("open outfile"); exit(1); }
            dip2(fd, STDOUT_FILENO);
            close(fd);
        }

        //execute
        execvp(cmd->argv[0], cmd->agrv);
        perror("execvp");
        exit(1);
    } else {
        //Parent
        if (cmd->background){
            //do not wait, optionally collect with waitpid(... WNOHANG) later
            printf("[bg] pid %d\n", pid);
            return 0;
        } else {
            int status;
            waitpid(pid, &status, 0);
            return status;
        }
    }
}