#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxSubArraySum(int *array, int arraySize) {
    int max = array[0], curr = array[0];
    for(int i = 1; i < arraySize; ++i) {
        curr = array[i] > curr + array[i] ? array[i] : curr + array[i];
        max = max > curr ? max : curr;
    }
    return max;
}

int main() {
    int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) && n != 0) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    fputs("Max subarray sum of [", stdout);
    bool firstNum = true;
    for(int i = 0; i < arraySize; ++i) {
        if(!firstNum)
            fputs(", ", stdout);
        printf("%d", array[i]);
        firstNum = false;
    }
    printf("] is %d\n", maxSubArraySum(array, arraySize));
    free(array);
    return 0;
}
