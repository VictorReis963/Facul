#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main (){
    pid_t pid = fork();
    if (pid == -1){
        perror("erro ao criar processo");
        return 1;
    }
    else if (pid ==0){
        execlp("ls", "ls",NULL);
        perror("Erro ao executar o execlp");
        exit(0);

    }
    else{
        wait(NULL);
        printf("Comando executado com sucesso.\n");
    }
    return 0;


}