#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *array, int *reg, int left, int right, long *swap) {
    if(left < right) {
        int mid = left + (right - left >> 1);
        MergeSort(array, reg, left, mid, swap);
        MergeSort(array, reg, mid + 1, right, swap);
        int leftPointer = left, rightPointer = mid + 1;
        for(int i = left; i <= right; ++i) {
            if(leftPointer > mid) {
                reg[i] = array[rightPointer++];
                *swap += mid - leftPointer + 1;
            } else if(rightPointer > right)
                reg[i] = array[leftPointer++];
            else if(array[leftPointer] <= array[rightPointer])
                reg[i] = array[leftPointer++];
            else {
                reg[i] = array[rightPointer++];
                *swap += mid - leftPointer + 1;
            }
        }
        for(int i = left; i <= right; ++i)
            array[i] = reg[i];
    }
}

int main() {
	int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) == 1) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    int reg[arraySize];
    long swap = 0;
    MergeSort(array, reg, 0, arraySize - 1, &swap);
    printf("Number of inversions: %ld\n", swap);
    free(array);
	return 0;
}
