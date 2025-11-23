#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int inicio;
    int fim;
} Atividade;

int comparar(const void *a, const void *b) {
    Atividade *x = (Atividade *)a;
    Atividade *y = (Atividade *)b;
    return x->fim - y->fim;
}

void selecionar_atividades(Atividade atividades[], int n) {
    qsort(atividades, n, sizeof(Atividade), comparar);

    printf("Atividades selecionadas:\n");

    int ultima_fim = -1;
    for (int i = 0; i < n; i++) {
        if (atividades[i].inicio >= ultima_fim) {
            printf("(%d, %d)\n", atividades[i].inicio, atividades[i].fim);
            ultima_fim = atividades[i].fim;
        }
    }
}

int main() {
    Atividade atividades[] = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    int n = sizeof(atividades) / sizeof(atividades[0]);
    selecionar_atividades(atividades, n);

    return 0;
}
