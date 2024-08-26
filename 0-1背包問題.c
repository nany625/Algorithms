#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
	bool selected[n][W + 1];
	memset(selected, 0, sizeof(selected));
	for(int i = 0; i < n; ++i) {
	    int w = items[i].weight;
	    int v = items[i].value;
	    for(int j = W; j >= w; --j) {
	        if(dp[j] < dp[j - w] + v) {
	            dp[j] = dp[j - w] + v;
	            selected[i][j] = true;
	        }
	    }
	}
	printf("Maximum value in 0/1 Knapsack: %d\n", dp[W]);
	puts("Items selected:");
	int currentW = W;
	for(int i = n - 1; i >= 0; --i) {
	    if(selected[i][currentW]) {
	        printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
	        currentW -= items[i].weight;
	    }
	}
	return 0;
}

/*
Input:
4
2 3
3 4
4 5
5 6
8

Output:
Maximum value in 0/1 Knapsack: 10
Items selected:
Item 4: Weight = 5, Value = 6
Item 2: Weight = 3, Value = 4
*/

/*
dp:
   | 0  1  2  3  4  5  6  7  8
---+--------------------------
 0 | 0  0  3  3  3  3  3  3  3
 1 | 0  0  3  4  4  7  7  7  7
 2 | 0  0  3  4  5  7  8  9  9
 3 | 0  0  3  4  5  7  8  9 10

selected:
   | 0  1  2  3  4  5  6  7  8
---+--------------------------
 0 | 0  0  1  1  1  1  1  1  1
 1 | 0  0  0  1  1  1  1  1  1
 2 | 0  0  0  0  1  0  1  1  1
 3 | 0  0  0  0  0  0  0  0  1
*/
