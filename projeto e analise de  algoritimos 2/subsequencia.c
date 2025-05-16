#include <stdio.h>
#include <string.h>

int memo[100][100]; // global para memoization

int lcs_recursive(char* X, char* Y, int i, int j);
int lcs_memo(char* X, char* Y, int i, int j);
int lcs_tabulation(char* X, char* Y, int m, int n);


int lcs_recursive(char* X, char* Y, int i, int j) {
    if (i == 0 || j == 0)
        return 0;

    if (X[i - 1] == Y[j - 1])
        return 1 + lcs_recursive(X, Y, i - 1, j - 1);
    else
        return (lcs_recursive(X, Y, i - 1, j) > lcs_recursive(X, Y, i, j - 1))
            ? lcs_recursive(X, Y, i - 1, j)
            : lcs_recursive(X, Y, i, j - 1);
}


int lcs_memo(char* X, char* Y, int i, int j) {
    if (i == 0 || j == 0)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (X[i - 1] == Y[j - 1])
        memo[i][j] = 1 + lcs_memo(X, Y, i - 1, j - 1);
    else {
        int a = lcs_memo(X, Y, i - 1, j);
        int b = lcs_memo(X, Y, i, j - 1);
        memo[i][j] = (a > b) ? a : b;
    }

    return memo[i][j];
}


int lcs_tabulation(char* X, char* Y, int m, int n) {
    int dp[100][100];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    return dp[m][n];
}


int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";

    int m = strlen(X);
    int n = strlen(Y);

    // Recursiva
    printf("SCM Recursiva: %d\n", lcs_recursive(X, Y, m, n));

    // Memoization
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            memo[i][j] = -1;
    printf("SCM Memoization: %d\n", lcs_memo(X, Y, m, n));

    // Tabulação
    printf("SCM Tabulation: %d\n", lcs_tabulation(X, Y, m, n));

    return 0;
}
