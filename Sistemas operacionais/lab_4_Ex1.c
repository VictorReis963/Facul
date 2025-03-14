#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("ERRO AO CRIAR PROCESSO!\n");
    } 
    else if (pid == 0) {
        printf("Eu sou o processo filho, meu PID é %d\n", getpid());
        return 1; // Child process exits
    } 
    else {
        printf("Eu sou o processo pai, meu PID é %d. E criei um filho com PID %d \n", getpid(), pid);
    }

    return 0;
}
