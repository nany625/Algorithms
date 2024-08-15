#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int dp[capacity + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < size; ++i) {
	    w = items[i].weight;
	    v = items[i].value;
	    for(int j = w; j <= capacity; ++j)
	        dp[j] = dp[j] > dp[j - w] + v ? dp[j] : dp[j - w] + v;
	}
	printf("Maximum value in Complete Knapsack: %d\n", dp[capacity]);
	free(items);
	return 0;
}
