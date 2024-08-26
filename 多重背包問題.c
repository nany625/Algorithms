#include <stdio.h>
#include <string.h>

typedef struct {
    int weight, value, amount;
} Item;

int main() {
	int n;
	scanf("%d", &n);
	Item items[n];
	for(int i = 0; i < n; ++i)
	    scanf("%d %d %d", &items[i].weight, &items[i].value, &items[i].amount);
	int W;
	scanf("%d", &W);
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; ++i) {
	    int w = items[i].weight;
	    int v = items[i].value;
	    int a = items[i].amount;
	    for(int k = 1; k <= a; k *= 2) {
	        int itemWeight = w * k;
	        int itemValue = v * k;
	        for(int j = W; j >= itemWeight; --j)
	            dp[j] = dp[j] > dp[j - itemWeight] + itemValue ? dp[j] : dp[j - itemWeight] + itemValue;
	        a -= k;
	    }
	    if(a > 0) {
	        int itemWeight = w * a;
	        int itemValue = v * a;
	        for(int j = W; j >= itemWeight; --j)
	            dp[j] = dp[j] > dp[j - itemWeight] + itemValue ? dp[j] : dp[j - itemWeight] + itemValue;
	    }
	}
	printf("Maximum value in Bounded Knapsack: %d\n", dp[W]);
	return 0;
}

/*
Input:
3
3 4 2
4 5 3
2 3 5
10

Output:
Maximum value in Bounded Knapsack: 15
*/

/*
Items are splitted to:
Item 1: {Weight = 3, Value = 4}, 
        {Weight = 3, Value = 4}
Item 2: {Weight = 4, Value = 5}, 
        {Weight = 8, Value = 10}
Item 3: {Weight = 2, Value = 3}, 
        {Weight = 4, Value = 6}, 
        {Weight = 4, Value = 6}
        
dp:
   | 0  1  2  3  4  5  6  7  8  9 10
---+--------------------------------
 0 | 0  0  0  4  4  4  4  4  4  4  4
 1 | 0  0  0  4  4  4  8  8  8  8  8
 2 | 0  0  0  4  5  5  8  9  9  9 13
 3 | 0  0  0  4  5  5  8  9 10 10 13
 4 | 0  0  3  4  5  7  8  9 11 12 13
 5 | 0  0  3  4  6  7  9 10 11 13 14
 6 | 0  0  3  4  6  7  9 10 12 13 15
*/
