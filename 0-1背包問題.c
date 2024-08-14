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
	int dp[capacity + 1];
	for(int i = 0; i <= capacity; ++i)
	    dp[i] = 0;
	for(int i = 0; i < size; ++i) {
	    for(int j = capacity; j >= items[i].weight; --j)
	        dp[j] = dp[j] > dp[j - items[i].weight] + items[i].value ? dp[j] : dp[j - items[i].weight] + items[i].value;
	}
	printf("Maximum value in Knapsack: %d\n", dp[capacity]);
	free(items);
	return 0;
}
