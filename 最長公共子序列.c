#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLCS(char *X, char *Y) {
    int m = strlen(X), n = strlen(Y);
    int LCS[m + 1][n + 1];
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(i == 0 || j == 0)
                LCS[i][j] = 0;
            else if(X[i - 1] == Y[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
        }
    }
    return LCS[m][n];
}

int main() {
    char *X = NULL, *Y = NULL;
    while(scanf("%ms %ms", &X, &Y) == 2) {
        printf("Length of LCS of string \"%s\" and \"%s\": %d\n", X, Y, lengthOfLCS(X, Y));
        free(X);
        free(Y);
        X = Y = NULL;
    }
    return 0;
}
