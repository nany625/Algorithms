#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLCS(char *X, char *Y) {
    int m = strlen(X), n = strlen(Y);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < m; ++i) {
        int prev = 0;
        for(int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if(X[i] == Y[j - 1])
                dp[j] = prev + 1;
            else
                dp[j] = dp[j] > dp[j - 1] ? dp[j] : dp[j - 1];
            prev = temp;
        }
    }
    return dp[n];
}

int main() {
    char *X = NULL, *Y = NULL;
    while(scanf("%ms %ms", &X, &Y) == 2) {
        printf("Length of LCS of strings \"%s\" and \"%s\": %d\n", X, Y, lengthOfLCS(X, Y));
        free(X);
        free(Y);
        X = Y = NULL;
    }
    return 0;
}
