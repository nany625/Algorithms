#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *array, int arraySize, int key) {
    int left = 0, right = arraySize - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int lengthOfLIS(int *array, int arraySize) {
    int *LIS = NULL, length = 0;
    for(int i = 0; i < arraySize; ++i) {
        int pos = binarySearch(LIS, length, array[i]);
        if(pos == length)
            LIS = (int*)realloc(LIS, ++length * sizeof(int));
        LIS[pos] = array[i];
    }
    free(LIS);
    return length;
}

int main() {
    int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) && n != 0) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    fputs("Length of LIS of [", stdout);
    for(int i = 0; i < arraySize - 1; ++i)
        printf("%d, ", array[i]);
    printf("%d] is %d\n", array[arraySize - 1], lengthOfLIS(array, arraySize));
    free(array);
    return 0;
}
