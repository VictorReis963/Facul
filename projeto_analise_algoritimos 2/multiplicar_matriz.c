#include <stdio.h>

int multiply_recursive(int A[][10], int B[][10], int m, int n, int p, int i, int j, int k) {
    if (k == n)
        return 0;
    return A[i][k] * B[k][j] + multiply_recursive(A, B, m, n, p, i, j, k + 1);
}

void matrix_recursive(int A[][10], int B[][10], int C[][10], int m, int n, int p) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = multiply_recursive(A, B, m, n, p, i, j, 0);
}


int memo[10][10][10]; // memo[i][j][k] para subproduto A[i][k] * B[k][j]

int multiply_memo(int A[][10], int B[][10], int m, int n, int p, int i, int j, int k) {
    if (k == n) return 0;
    if (memo[i][j][k] != -1) return memo[i][j][k];

    memo[i][j][k] = A[i][k] * B[k][j] + multiply_memo(A, B, m, n, p, i, j, k + 1);
    return memo[i][j][k];
}

void matrix_memo(int A[][10], int B[][10], int C[][10], int m, int n, int p) {
       for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < n; k++)
                memo[i][j][k] = -1;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = multiply_memo(A, B, m, n, p, i, j, 0);
}


void matrix_tabulation(int A[][10], int B[][10], int C[][10], int m, int n, int p) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}


int A[10][10], B[10][10], C[10][10];

int main() {
    int m = 2, n = 3, p = 2;

    // exemplo: A = 2x3, B = 3x2
    int a[2][10] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][10] = {{7, 8}, {9, 10}, {11, 12}};

    // copiando para variaveis 
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) A[i][j] = a[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < p; j++) B[i][j] = b[i][j];

    // Chame a versão que quiser aqui
    matrix_tabulation(A, B, C, m, n, p); // ou matrix_recursive / matrix_memo

    printf("Resultado da multiplicação:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
