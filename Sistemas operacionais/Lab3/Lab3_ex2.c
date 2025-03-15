#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    pid_t pid = fork();
    if (pid == -1){
        perror("Erro ao criar processo");
        return 1;
    }
    else if (pid == 0){ //processo filho executa
        for (int i=0; i<5;i++){
            printf("caneta Azul, azul caneta %d/5\n",i);
            sleep (5);

        }
        exit(0);
    
    }  
    else{
        //processo pai executa apos o filho terminar
        wait(NULL);
        printf("processo filho finazlizado!!");
    }
    return 0;

}