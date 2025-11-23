#include <stdio.h>
#include <limits.h>

#define MAX_MOEDAS 100

int melhor_resultado[MAX_MOEDAS];
int melhor_tamanho = INT_MAX;

void copiar_solucao(int origem[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        melhor_resultado[i] = origem[i];
    }
    melhor_tamanho = tamanho;
}

void backtrack(int moedas[], int n, int valor, int idx, int atual[], int tamanho_atual) {
    if (valor == 0) {
        if (tamanho_atual < melhor_tamanho) {
            copiar_solucao(atual, tamanho_atual);
        }
        return;
    }
    if (idx >= n || valor < 0 || tamanho_atual >= melhor_tamanho) return;

    int max_usar = valor / moedas[idx];
    for (int i = max_usar; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            atual[tamanho_atual + j] = moedas[idx];
        }
        backtrack(moedas, n, valor - moedas[idx]*i, idx + 1, atual, tamanho_atual + i);
    }
}

int main() {
    int moedas[] = {1, 5, 10, 25};
    int n = sizeof(moedas) / sizeof(moedas[0]);
    int valor = 63;
    int atual[MAX_MOEDAS];

    // Ordena moedas do maior para o menor (bubble sort)
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (moedas[j] < moedas[j+1]) {
                int temp = moedas[j];
                moedas[j] = moedas[j+1];
                moedas[j+1] = temp;
            }
        }
    }

    backtrack(moedas, n, valor, 0, atual, 0);

    printf("Troco (Backtracking): ");
    for (int i = 0; i < melhor_tamanho; i++) {
        printf("%d ", melhor_resultado[i]);
    }
    printf("\n");

    return 0;
}
