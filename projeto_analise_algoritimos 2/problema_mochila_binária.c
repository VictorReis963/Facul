#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochila_01(int capacidade, int pesos[], int valores[], int n) {
    int dp[n+1][capacidade+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacidade; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (pesos[i-1] <= w)
                dp[i][w] = max(valores[i-1] + dp[i-1][w - pesos[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacidade];
}

int main() {
    int valores[] = {60, 100, 120};
    int pesos[] = {10, 20, 30};
    int capacidade = 50;
    int n = sizeof(valores) / sizeof(valores[0]);

    int resultado = mochila_01(capacidade, pesos, valores, n);
    printf("Valor máximo (mochila 0-1): %d\n", resultado);

    return 0;
}
