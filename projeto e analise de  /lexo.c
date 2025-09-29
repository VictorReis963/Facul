#include <stdio.h>

#define MAX_PALAVRAS 100
#define MAX_TAM 100

// Função que compara duas strings lexicograficamente
int comparar(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;  // str1 vem antes
        if (str1[i] > str2[i]) return 1;   // str1 vem depois
        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0') return -1; // str1 é menor
    if (str1[i] != '\0' && str2[i] == '\0') return 1;  // str2 é menor
    return 0; // são iguais
}

// Função que copia uma string para outra
void copiar(char destino[], char origem[]) {
    int i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

// Função que faz o Insertion Sort das palavras
void ordenar(char palavras[][MAX_TAM], int n) {
    char chave[MAX_TAM];
    int i, j;

    for (i = 1; i < n; i++) {
        copiar(chave, palavras[i]);
        j = i - 1;

        // Move as palavras maiores para a direita
        while (j >= 0 && comparar(palavras[j], chave) > 0) {
            copiar(palavras[j + 1], palavras[j]);
            j--;
        }
        copiar(palavras[j + 1], chave);
    }
}

int main() {
    int n, i;
    char palavras[MAX_PALAVRAS][MAX_TAM];

    printf("Quantas palavras você quer ordenar? ");
    scanf("%d", &n);

    printf("Digite as palavras:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", palavras[i]);
    }

    ordenar(palavras, n);

    printf("\nPalavras ordenadas lexicograficamente:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", palavras[i]);
    }

    return 0;
}
