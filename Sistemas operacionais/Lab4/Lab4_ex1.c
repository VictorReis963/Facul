#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    if (pid == -1){
        perror("Erro ao criar processo");
        return 1;
    }
    if (pid == 0){
        printf("sou o processo filho, com o PID de: %d \n",getpid());
    }
    else{
        printf("Sou o processo Pai, PID = %d. E criei um filho com o PID= %d. \n", getpid(), pid);
    }

}