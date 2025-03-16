#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main (){
    int f,i;
    printf("Insira a quantidade de filhos");
    scanf("%d", &f);

    for (i=1; i<=f; i++){
      pid_t pid = fork();
      if (pid == -1){
         perror("erro ao criar processo");
         return 1;
     }
      else if (pid ==0){
        printf("sou o %dº processo filho , com o PID de n: %d, e meu pai é o Sr. %d \n",i,getpid(),getppid());
        exit(0);
        }

        for (int j=1; j<=f; j++){
            wait(NULL);
              
        }
    }
    printf("todos os processos filhos estão finalizados");
    return 0;
     }


    