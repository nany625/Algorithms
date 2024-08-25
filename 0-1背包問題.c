#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int weight, value;
} Item;

int main() {
	Item *items = NULL;
	int n = 0, w, v;
	while(scanf("%d %d", &w, &v) && w != 0 && v != 0) {
	    items = (Item*)realloc(items, (n + 1) * sizeof(Item));
	    items[n].weight = w;
	    items[n++].value = v;
	}
	int W;
	scanf("%d", &W);
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));
	bool selected[n][W + 1];
	memset(selected, 0, sizeof(selected));
	for(int i = 0; i < n; ++i) {
	    w = items[i].weight;
	    v = items[i].value;
	    for(int j = W; j >= w; --j) {
	        if(dp[j] < dp[j - w] + v) {
	            dp[j] = dp[j - w] + v;
	            selected[i][j] = true;
	        }
	    }
	}
	printf("Maximum value in Knapsack: %d\n", dp[W]);
	puts("Items selected:");
	int currentW = W;
	for(int i = n - 1; i >= 0; --i) {
	    if(selected[i][currentW]) {
	        printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
	        currentW -= items[i].weight;
	    }
	}
	free(items);
	return 0;
}

/*
Input:
2 3
3 4
4 5
5 6
0 0
8

Output:
Maximum value in Knapsack: 10
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
