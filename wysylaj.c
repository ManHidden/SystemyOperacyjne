//
// Created by patryk on 24.03.18.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
    #include <memory.h>
#include <wait.h>

int main(int argc, char *argv[]){

    if(argc >= 2 && argc < 3){
        printf("Podałeś za małą liczbę argumentów, argc: %d\n", argc);
        exit(2);
    }

    signal(atoi(argv[1]), SIG_IGN);

    switch(fork()){
        case -1:
            perror("Fork error\n");
            break;
        case 0:
            printf("Utworzono proces potomny\n");
            execl("obsluguj", "obsluguj.c", argv[1], argv[2], (char *)0);
            kill(getpid(), atoi(argv[1]));
            wait(0);
            break;
        default:
            printf("Default\n");
            break;
    }




}