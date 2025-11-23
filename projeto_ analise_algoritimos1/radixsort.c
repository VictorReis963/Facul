#include <stdio.h>

void countingSort(int v[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // conta quantas vezes cada dígito aparece
    for(int i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;

    // transforma count em posições acumuladas
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // monta o vetor final (de trás pra frente p/ manter estabilidade)
    for(int i = n - 1; i >= 0; i--) {
        int digit = (v[i] / exp) % 10;
        output[count[digit] - 1] = v[i];
        count[digit]--;
    }

    // copia pra array original
    for(int i = 0; i < n; i++)
        v[i] = output[i];
}

void radixSort(int v[], int n) {
    int maior = v[0];
    for(int i = 1; i < n; i++)
        if(v[i] > maior)
            maior = v[i];

    // aplica counting sort para cada dígito
    for(int exp = 1; maior / exp > 0; exp *= 10)
        countingSort(v, n, exp);
}

int main() {
    int v[] = {472, 159, 3, 824, 111};
    int n = 5;

    radixSort(v, n);

    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}
