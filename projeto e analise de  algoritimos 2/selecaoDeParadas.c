#include <stdio.h>

int selecao_paradas(int postos[], int n, int autonomia) {
    int num_paradas = 0;
    int pos_atual = 0;
    int ultimo_abastecido = 0;

    while (pos_atual < n - 1) {
        int proximo = pos_atual;

        while (proximo + 1 < n && postos[proximo + 1] - postos[pos_atual] <= autonomia) {
            proximo++;
        }

        if (proximo == pos_atual) {
            return -1;
        }

        if (proximo < n - 1) {
            num_paradas++;
        }

        pos_atual = proximo;
    }

    return num_paradas;
}

int main() {
    int postos[] = {0, 100, 200, 300, 400, 500}; 
    int n = sizeof(postos) / sizeof(postos[0]);
    int autonomia = 200;

    int resultado = selecao_paradas(postos, n, autonomia);
    if (resultado != -1)
        printf("Número mínimo de paradas: %d\n", resultado);
    else
        printf("Não é possível alcançar o destino com essa autonomia.\n");

    return 0;
}
