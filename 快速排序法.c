#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, int left, int right) {
    int curr = left, pivot = array[right];
    for(int i = left; i < right; ++i) {
        if(array[i] < pivot)
            swap(&array[curr++], &array[i]);
    }
    swap(&array[curr], &array[right]);
    return curr;
}

void QuickSort(int *array, int left, int right) {
    if(left < right) {
        int partitionIndex = partition(array, left, right);
        QuickSort(array, left, partitionIndex - 1);
        QuickSort(array, partitionIndex + 1, right);
    }
}

int main() {
    int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) == 1) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    QuickSort(array, 0, arraySize - 1);
    for(int i = 0; i < arraySize; ++i) {
        if(i > 0)
            fputs(", ", stdout);
        printf("%d", array[i]);
    }
    putchar('\n');
    free(array);
    return 0;
}
