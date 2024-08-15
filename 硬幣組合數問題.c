#include <stdio.h>
#include <stdlib.h>

int main() {
    int *coins = NULL, size = 0, coin;
    while(scanf("%d", &coin) && coin != 0) {
        coins = (int*)realloc(coins, (size + 1) * sizeof(int));
        coins[size++] = coin;
    }
    int amount;
    while(scanf("%d", &amount) == 1) {
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < size; ++i) {
            for(int j = coins[i]; j <= amount; ++j)
                dp[j] += dp[j - coins[i]];
        }
        printf("%d\n", dp[amount]);
    }
    free(coins);
    return 0;
}
