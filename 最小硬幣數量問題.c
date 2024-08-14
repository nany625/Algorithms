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
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            dp[i] = amount + 1;
            for(int j = 0; j < size; ++j) {
                if(i >= coins[j])
                    dp[i] = dp[i] < dp[i - coins[j]] + 1 ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
        printf("%d\n", dp[amount] > amount ? -1 : dp[amount]);
    }
    free(coins);
    return 0;
}
