#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TARGET 100000

long dp[MAX_TARGET + 1];

int main() {
    
    int *coins = NULL, n = 0, value;
    while(scanf("%d", &value) && value != 0) {
        coins = (int*)realloc(coins, (n + 1) * sizeof(int));
        coins[n++] = value;
    }
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = coins[i]; j <= MAX_TARGET; ++j)
            dp[j] += dp[j - coins[i]];
    }
    int target;
    while(scanf("%d", &target) == 1)
        printf("Number of combinations to make $%d: %ld\n", target, dp[target]);
    free(coins);
    return 0;
}

/*
Input:
1 2 5 10 20 50 0
0
1
2
3
5
25
100
325
1000
3000
8000
10000
50000
100000

Output:
Number of combinations to make $0: 1
Number of combinations to make $1: 1
Number of combinations to make $2: 2
Number of combinations to make $3: 2
Number of combinations to make $5: 4
Number of combinations to make $25: 68
Number of combinations to make $100: 4562
Number of combinations to make $325: 559632
Number of combinations to make $1000: 103119386
Number of combinations to make $3000: 21773421656
Number of combinations to make $8000: 2806483881081
Number of combinations to make $10000: 8518079396351
Number of combinations to make $50000: 26156426151481751
Number of combinations to make $100000: 835168075439213501
*/
