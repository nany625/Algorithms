#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSubsetSum(int *array, int arraySize, int sum) {
    bool subsetSum[sum + 1];
    subsetSum[0] = true;
    memset(subsetSum + 1, 0, sum * sizeof(bool));
    for(int i = 0; i < arraySize && !subsetSum[sum]; ++i) {
        for(int j = sum; j >= array[i] && !subsetSum[sum]; --j)
            subsetSum[j] |= subsetSum[j - array[i]];
    }
    return subsetSum[sum];
}

int main() {
    int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) && n != 0) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    int sum;
    scanf("%d", &sum);
    printf("%d is %ssubsetsum of [", sum, isSubsetSum(array, arraySize, sum) ? "" : "not ");
    for(int i = 0; i < arraySize - 1; ++i)
        printf("%d, ", array[i]);
    printf("%d]\n", array[arraySize - 1]);
    free(array);
    return 0;
}
