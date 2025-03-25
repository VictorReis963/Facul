#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutacoes(int n[], int l, int r) {
    if (l == r) {
        for (int i = 0; i <= r; i++) {
            printf("%d ", n[i]);
        }
        printf("\n");
    } else {
        for (int i = l; i <= r; i++) {
            troca(&n[l], &n[i]);
            permutacoes(n, l + 1, r);
            troca(&n[l], &n[i]);
        }
    }
}

int main() {
    int n[] = {1, 2, 3};
    permutacoes(n, 0, 2);
    printf("Vetor finalizado: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
    return 0;
}