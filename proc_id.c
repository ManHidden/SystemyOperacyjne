//
// Created by patryk on 11.03.18.
//
#include "stdio.h"
#include <unistd.h>


void proc_id(){
    __pid_t pid;

    printf("PID: %d, PPID: %d, PGID: %d, UID: %d, GID: %d\n", getpid(), getppid(), getpgid(pid), getuid(), getgid());
    sleep(1);
}

