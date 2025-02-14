#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 10000

int dp[MAX_AMOUNT + 1];

int main() {
    int *coins = NULL, n = 0, value;
    while(scanf("%d", &value) && value != 0) {
        coins = (int*)realloc(coins, (n + 1) * sizeof(int));
        coins[n++] = value;
    }
    for(int i = 1; i <= MAX_AMOUNT; ++i) {
        dp[i] = MAX_AMOUNT + 1;
        for(int j = 0; j < n; ++j) {
            if(i >= coins[j])
                dp[i] = dp[i] < dp[i - coins[j]] + 1 ? dp[i] : dp[i - coins[j]] + 1;
        }
    }
    int amount;
    while(scanf("%d", &amount) == 1) {
        if(dp[amount] <= MAX_AMOUNT)
            printf("Minimum coins required to make $%d: %d\n", amount, dp[amount]);
        else
            printf("It's not possible to make $%d with the given coins.\n", amount);
    }
    free(coins);
    return 0;
}

/*
Input:
3 5 10 12 20 50 100 180 500 1000 0
0
1
2
5
15
25
80
120
190
720
1350
3700
6666
10000

Ouptut:
Minimum coins required to make $0: 0
It's not possible to make $1 with the given coins.
It's not possible to make $2 with the given coins.
Minimum coins required to make $5: 1
Minimum coins required to make $15: 2
Minimum coins required to make $25: 2
Minimum coins required to make $80: 3
Minimum coins required to make $120: 2
Minimum coins required to make $190: 2
Minimum coins required to make $720: 4
Minimum coins required to make $1350: 5
Minimum coins required to make $3700: 6
Minimum coins required to make $6666: 12
Minimum coins required to make $10000: 10
*/
