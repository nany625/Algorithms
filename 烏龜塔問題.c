#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int weight, strength;
} Turtle;

int compare(const void *a, const void *b) {
    return ((Turtle*)a)->strength > ((Turtle*)b)->strength;
}

int main() {
    Turtle *turtles = NULL;
    int size = 0, w, s;
    while(scanf("%d %d", &w, &s) == 2) {
        turtles = (Turtle*)realloc(turtles, (size + 1) * sizeof(Turtle));
        turtles[size].weight = w;
        turtles[size++].strength = s;
    }
    qsort(turtles, size, sizeof(Turtle), compare);
    int dp[size + 1];
    dp[0] = 0;
    for(int i = 1; i <= size; ++i)
        dp[i] = INT_MAX;
    int maxHeight = 0;
    for(int i = 0; i < size; ++i) {
        for(int j = maxHeight; j >= 0; j--) {
            if(dp[j] + turtles[i].weight <= turtles[i].strength) {
                dp[j + 1] = dp[j + 1] < dp[j] + turtles[i].weight ? dp[j + 1] : dp[j] + turtles[i].weight;
                if(dp[j + 1] != INT_MAX)
                    maxHeight = maxHeight > j + 1 ? maxHeight : j + 1;
            }
        }
    }
    printf("Maximum height of turtle tower: %d\n", maxHeight);
    free(turtles);
    return 0;
}
