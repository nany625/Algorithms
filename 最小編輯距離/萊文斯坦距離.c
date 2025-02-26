#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    b = b < a ? b : a;
    return c < b ? c : b;
}

int levenshteinDistance(char *X, char *Y) {
    int m = strlen(X), n = strlen(Y);
    int dp[n + 1];
    for(int i = 0; i <= n; ++i)
        dp[i] = i;
    for(int i = 1; i <= m; ++i) {
        int prev = dp[0];
        dp[0] = i;
        for(int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if(X[i - 1] == Y[j - 1])
                dp[j] = prev;
            else
                dp[j] = 1 + min(dp[j], dp[j - 1], prev);
            prev = temp;
        }
    }
    return dp[n];
}

int main() {
    char *X = NULL, *Y = NULL;
    while(scanf("%ms %ms", &X, &Y) == 2) {
        printf("Levenshtein Distance of strings \"%s\" and \"%s\": %d\n", X, Y, levenshteinDistance(X, Y));
        free(X);
        free(Y);
        X = Y = NULL;
    }
	return 0;
}
