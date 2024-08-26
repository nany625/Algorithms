#include <stdio.h>
#include <string.h>

typedef struct {
    int weight, value;
} Item;

int main() {
	int n;
	scanf("%d", &n);
	Item items[n];
	for(int i = 0; i < n; ++i)
	    scanf("%d %d", &items[i].weight, &items[i].value);
	int W;
	scanf("%d", &W);
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; ++i) {
	    int w = items[i].weight;
	    int v = items[i].value;
	    for(int j = w; j <= W; ++j)
	        dp[j] = dp[j] > dp[j - w] + v ? dp[j] : dp[j - w] + v;
	}
	printf("Maximum value in Complete Knapsack: %d\n", dp[W]);
	return 0;
}

/*
Input:
4
2 3
3 4
4 5
5 6
9

Output:
Maximum value in Complete Knapsack: 13
*/

/*
dp:
   | 0  1  2  3  4  5  6  7  8  9
---+-----------------------------
 0 | 0  0  3  3  6  6  9  9 12 12
 1 | 0  0  3  4  6  7  9 10 12 13
 2 | 0  0  3  4  6  7  9 10 12 13
 3 | 0  0  3  4  6  7  9 10 12 13
*/
