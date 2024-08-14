#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, value;
} Item;

int compare(const void *a, const void *b) {
    Item *i1 = (Item*)a;
    Item *i2 = (Item*)b;
    return (double)i1->value / i1->weight < (double)i2->value / i2->weight;
}

int main() {
	Item *items = NULL;
	int size = 0, w, v;
	while(scanf("%d %d", &w, &v) && w != 0 && v != 0) {
	    items = (Item*)realloc(items, (size + 1) * sizeof(Item));
	    items[size].weight = w;
	    items[size++].value = v;
	}
	qsort(items, size, sizeof(Item), compare);
	int capacity;
	scanf("%d", &capacity);
	double maxValue = 0;
	for(int i = 0; i < size; ++i) {
	    if(capacity >= items[i].weight) {
	        maxValue += items[i].value;
	        capacity -= items[i].weight;
	    } else {
	        maxValue += capacity * (double)items[i].value / items[i].weight;
	        break;
	    }
	}
	printf("Maximum value in Fractional Knapsack: %.2lf\n", maxValue);
	free(items);
	return 0;
}
