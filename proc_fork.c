//
// Created by patryk on 11.03.18.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void proc_fork(){
    pid_t pid;
    printf("Macierzysty -> PID: %d, PPID: %d, PGID: %d\n", getpid(), getppid(), getpgid(pid));
    for(int i = 0; i < 3; i++) {
        switch (fork()) {
            case -1:
                perror("Nie udało się przeprowadzić forku");
                exit(1);
            case 0:
                printf("Potomek ->     PID: %d, PPID: %d, PGID: %d\n", getpid(), getppid(), getpgid(pid));
            default:
                sleep(1);
        }
    }
}

int main(){
    proc_fork();

    return 0;
}