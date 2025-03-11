#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("ERRO AO CRIAR PROCESSO!\n");
        return 1;
    } 
    else if (pid == 0) {
        int c;
        while (c!=4){
            printf( "caneta Azul");
            c++;
            sleep(10);
        }
        printf("Eu sou o processo filho, meu PID é %d\n", getpid());
         // Child process exits
         exit(0);
    } 
    else {
        Wait(NULL);
        printf("Eu sou o processo pai, meu PID é %d. E criei um Lerdo filho com PID %d \n", getpid(), pid);
    }

    return 0;
}
