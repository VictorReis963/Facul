#include <stdio.h>

void troco_guloso(int valor, int moedas[], int n) {
    printf("Troco (Guloso): ");
    for (int i = n - 1; i >= 0; i--) {
        while (valor >= moedas[i]) {
            valor -= moedas[i];
            printf("%d ", moedas[i]);
        }
    }
    printf("\n");
}

int main() {
    int moedas[] = {1, 5, 10, 25};
    int n = sizeof(moedas) / sizeof(moedas[0]);
    int valor = 63;

    // Ordena as moedas (Bubble Sort) - do menor para o maior
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (moedas[j] > moedas[j+1]) {
                int temp = moedas[j];
                moedas[j] = moedas[j+1];
                moedas[j+1] = temp;
            }
        }
    }

    troco_guloso(valor, moedas, n);
    return 0;
}
