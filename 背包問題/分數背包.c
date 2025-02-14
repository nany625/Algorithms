#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
} Item;

int compare(const void *a, const void *b) {
    Item *i1 = (Item*)a;
    Item *i2 = (Item*)b;
    return i1->value * i2->weight < i2->value * i1->weight;
}

int main() {
    int n;
    scanf("%d", &n);
	Item items[n];
	for(int i = 0; i < n; ++i)
	    scanf("%d %d", &items[i].weight, &items[i].value);
	qsort(items, n, sizeof(Item), compare);
	int W;
	scanf("%d", &W);
	double maxValue = 0;
	for(int i = 0; i < n; ++i) {
	    if(W >= items[i].weight) {
	        maxValue += items[i].value;
	        W -= items[i].weight;
	    } else {
	        maxValue += W * (double)items[i].value / items[i].weight;
	        break;
	    }
	}
	printf("Maximum value in Fractional Knapsack: %.2lf\n", maxValue);
	return 0;
}
