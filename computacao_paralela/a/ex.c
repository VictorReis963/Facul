#include <pthread.h>

typedef struct{   
    int linha;
    int n;
    int **A,**B,**C;
} DadosThread;

void* calcular(void* arg){
    DadosThread* dados = (DadosThread*) arg;
    int i = dados -> linha;

    return NULL;
}



int main(){
    DadosThread d;
    int mat[2][2]={{1,2}, {2,1}};
    d.A=mat;

    pthread_t t1;

    pthread_create(&t1, NULL, tarefa, NULL);

    pthread_join(t1, NULL);

    printf("programa feliz");

    return 0;
}