//
// Created by patryk on 24.03.18.
//
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <memory.h>
#include <unistd.h>


void ignore_signal(int signumer){
    printf("Ignorowanie sygnału, pracuję dalej %d\n", signumer);
    perror("Ignorowanie sygnału: ");
}

void handle_signal(int signumer){
    printf("Sygnal %d został obsłużony. Kończę program.\n", signumer);
    perror("Obsługa sygnału: ");
    exit(signumer);
}


int main(int argc, char *argv[]){

    if(argc >= 2 && argc < 3){
        printf("Podałeś za małą liczbę argumentów, argc: %d\n", argc);
        exit(2);
    }
	else if(strcmp(argv[2], "o") == 0){
		signal(atoi(argv[1]), handle_signal);
        while(1){
            printf("Signal handler\n");
            sleep(1);
        }
	}
	else if(strcmp(argv[2], "i") == 0){
        //signal(atoi(argv[1]), ignore_signal);
        signal(atoi(argv[1]), SIG_IGN);
        while(1){
            printf("Signal ignore\n");
            sleep(1);
        }

	}
    else if(strcmp(argv[2], "d") == 0){
        while(1){
            printf("Tryb domyślny\n");
            signal(atoi(argv[1]), SIG_DFL);
            sleep(1);
        }
	}

}
