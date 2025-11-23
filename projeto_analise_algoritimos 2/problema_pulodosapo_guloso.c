#include <stdio.h>

int salto_sapo(int A[], int n) {
    int pulos = 0;
    int alcanceAtual = 0;
    int proximoAlcance = 0;

    for (int i = 0; i < n - 1; i++) {
        proximoAlcance = (i + A[i] > proximoAlcance) ? i + A[i] : proximoAlcance;

        if (i == alcanceAtual) {
            pulos++;
            alcanceAtual = proximoAlcance;

            if (alcanceAtual >= n - 1)
                break;
        }
    }

    return (alcanceAtual >= n - 1) ? pulos : -1; // -1 se não for possível chegar
}

int main() {
    int A[] = {2, 3, 1, 1, 4};
    int n = sizeof(A) / sizeof(A[0]);

    int resultado = salto_sapo(A, n);
    if (resultado != -1)
        printf("Menor número de pulos: %d\n", resultado);
    else
        printf("Não é possível alcançar o final.\n");

    return 0;
}
