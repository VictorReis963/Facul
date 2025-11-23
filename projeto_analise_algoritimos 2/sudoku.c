#include <stdio.h>
#include <stdbool.h>

#define N 4

void mostra_matriz(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool valor_valido(int num, int m[N][N], int linha, int coluna) {
    for (int x = 0; x < N; x++) {
        if (m[linha][x] == num || m[x][coluna] == num)
            return false;
    }
    
    int inicio_linha = (linha / 2) * 2;
    int inicio_coluna = (coluna / 2) * 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (m[inicio_linha + i][inicio_coluna + j] == num)
                return false;
        }
    }
    return true;
}

void sudoku(int m[N][N], int linha, int coluna) {
    if (coluna == N) {
        linha++;
        coluna = 0;
    }
    if (linha == N) {
        mostra_matriz(m);
        return;
    }
    if (m[linha][coluna] > 0) {
        sudoku(m, linha, coluna + 1);
    } else {
        for (int i = 1; i <= N; i++) {
            if (valor_valido(i, m, linha, coluna)) {
                m[linha][coluna] = i;
                sudoku(m, linha, coluna + 1);
                m[linha][coluna] = 0;
            }
        }
    }
}

int main() {
    int m[N][N] = {
        {0, 0, 1, 0},
        {0, 0, 0, 2},
        {0, 0, 0, 3},
        {0, 4, 0, 0}
    };
    sudoku(m, 0, 0);
    return 0;
}
