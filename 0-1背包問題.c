#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
} Item;

int main() {
	Item *items = NULL;
	int size = 0, w, v;
	while(scanf("%d %d", &w, &v) && w != 0 && v != 0) {
	    items = (Item*)realloc(items, (size + 1) * sizeof(Item));
	    items[size].weight = w;
	    items[size++].value = v;
	}
	int capacity;
	scanf("%d", &capacity);
	int dp[size + 1][capacity + 1];
	for(int i = 0; i <= capacity; ++i)
	    dp[0][i] = 0;
	for(int i = 1; i <= size; ++i) {
	    w = items[i - 1].weight;
	    v = items[i - 1].value;
	    for(int j = 0; j <= capacity; ++j) {
	        if(j == 0)
	            dp[i][j] = 0;
	        else if(j >= w)
	            dp[i][j] = dp[i - 1][j] > dp[i - 1][j - w] + v ? dp[i - 1][j] : dp[i - 1][j - w] + v;
	        else
	            dp[i][j] = dp[i - 1][j];
	    }
	}
	printf("Maximum value in Knapsack: %d\n", dp[size][capacity]);
	free(items);
	return 0;
}
