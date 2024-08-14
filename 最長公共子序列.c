#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLCS(char *X, char *Y) {
    int m = strlen(X), n = strlen(Y);
    int LCS[n + 1];
    for(int i = 0; i <= n; ++i)
        LCS[i] = 0;
    for(int i = 0; i < m; ++i) {
        int prev = 0;
        for(int j = 1; j <= n; ++j) {
            int temp = LCS[j];
            if(X[i] == Y[j - 1])
                LCS[j] = prev + 1;
            else
                LCS[j] = LCS[j] > LCS[j - 1] ? LCS[j] : LCS[j - 1];
            prev = temp;
        }
    }
    return LCS[n];
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
