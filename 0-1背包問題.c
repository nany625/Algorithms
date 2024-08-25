#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
	bool selected[size][capacity + 1];
	memset(selected, 0, sizeof(selected));
	for(int i = 0; i < size; ++i) {
	    w = items[i].weight;
	    v = items[i].value;
	    for(int j = capacity; j >= w; --j) {
	        if(dp[j] < dp[j - w] + v) {
	            dp[j] = dp[j - w] + v;
	            selected[i][j] = true;
	        }
	    }
	}
	printf("Maximum value in Knapsack: %d\n", dp[capacity]);
	puts("Items selected:");
	int currentCapacity = capacity;
	for(int i = size - 1; i >= 0; --i) {
	    if(selected[i][currentCapacity]) {
	        printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
	        currentCapacity -= items[i].weight;
	    }
	}
	free(items);
	return 0;
}

/*
input:
2 3
3 4
4 5
5 6
0 0
8

output:
Maximum value in Knapsack: 10
Items selected:
Item 4: Weight = 5, Value = 6
Item 2: Weight = 3, Value = 4
*/

/*
dp:
0  0  3  3  3  3  3  3  3
0  0  3  4  4  7  7  7  7
0  0  3  4  5  7  8  9  9
0  0  3  4  5  7  8  9 10

selected:
0  0  1  1  1  1  1  1  1
0  0  0  1  1  1  1  1  1
0  0  0  0  1  0  1  1  1
0  0  0  0  0  0  0  0  1
*/
