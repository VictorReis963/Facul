#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();

    int f;
    printf("QUANTOS FILHOS VC QUER?");
    scanf("%d",&f);

    for (int i=0;i<=f;i++){
            if (pid<0){
                fprintf(stderr,"Fork falhou\n");
                return 1;
            }else if (pid==0){
                printf("Eu sou o filho! Meu PID é: %d, e meu pai é: %d", getpid(),getppid());
                return 0;
            }


        }
    for (int i=0;i<f;i++){
        wait(NULL);
    }
    printf("Todos os filhos acabaram, adeus");
        return 0;
    }