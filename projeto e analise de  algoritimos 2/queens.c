#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int N=8;
bool esta_salva(char tabuleiro[][N], int linha, int coluna) {
    int i, j;
    
    // Verifica a linha à esquerda
    for (i = 0; i < coluna; i++){ 
        if (tabuleiro[linha][i] == 'Q') 
            return false;
    }
    
    // Verifica a diagonal superior esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--){
        if (tabuleiro[i][j] == 'Q') 
            return false;
    }
    // Verifica a diagonal inferior esquerda
    for (i = linha, j = coluna; i < N && j >= 0; i++, j--){
        if (tabuleiro[i][j] == 'Q') 
            return false;
    }
    
    return true;
}
void posiciona_rainha(char tabuleiro[][N], int coluna) {
    if (coluna == N) {
        mostra_matriz(tabuleiro);
    } else {
        for (int i = 0; i < N; i++) {
            if (esta_salva(tabuleiro, i, coluna)) {
                tabuleiro[i][coluna] = 'Q';
                posiciona_rainha(tabuleiro, coluna + 1);
                tabuleiro[i][coluna] = '-';
            }
        }
    }
}
void cria_tabuleiro(char tabuleiro[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = '_';
        }
    }
}
void mostra_matriz(char tabuleiro[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int N=8;
    char tabuleiro[N][N];
    memset(tabuleiro, '-', sizeof(tabuleiro));
    
    posiciona_rainha(tabuleiro, 0);
    
    return 0;

}