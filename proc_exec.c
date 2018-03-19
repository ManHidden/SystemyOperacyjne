//
// Created by patryk on 11.03.18.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "proc_exec.h"

void proc_exec(){
    pid_t pid;
    int status = 0;
    for(int i = 0; i < 3; i++) {
        switch (fork()) {
            case -1:
                perror("Nie udało się przeprowadzić forku");
                exit(1);
            case 0:
                execl("proc_id","proc_id", NULL);
            default:
                wait(&status);
        }
    }
}

int main(){
    proc_exec();
}