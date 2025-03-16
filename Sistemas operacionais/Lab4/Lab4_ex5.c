#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void pai(int n) {
    if (n == 0) {
        printf("Fim da geração de filhos XD\n");
        return;
    }

    pid_t pid = fork();
    
    if (pid ==-1) {
        perror("Erro ao criar processo");
        exit(1);
    } 
    else if (pid == 0) {  // Processo filho
        pai(n - 1);
        printf("Eu sou o processo %d, e meu pai é %d\n", getpid(), getppid());
        exit(0);
    } 
    else {  // Processo pai espera 
        wait(NULL);
    }
}

int main() {
    int n = 3;  // numero de processos filhos a serem criados
    pai(n);
    printf("Todos os processos terminaram!!\n");
    return 0;
}
