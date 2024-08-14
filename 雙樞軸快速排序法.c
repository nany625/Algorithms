#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void DualPivotPartition(int *array, int *partitionIndices, int left, int right) {
	if(array[left] > array[right])
		swap(&array[left], &array[right]);
	int low = left + 1, high = right - 1, pivot1 = array[left], pivot2 = array[right];
	for(int i = low; i <= high; ++i) {
		if(array[i] < pivot1)
			swap(&array[low++], &array[i]);
		else if(array[i] > pivot2)
			swap(&array[high--], &array[i--]);
	}
	swap(&array[--low], &array[left]);
	swap(&array[++high], &array[right]);
	partitionIndices[0] = low;
	partitionIndices[1] = high;
}

void DualPivotQuickSort(int *array, int left, int right) {
    if(left < right) {
        int partitionIndices[2];
        DualPivotPartition(array, partitionIndices, left, right);
		DualPivotQuickSort(array, left, partitionIndices[0] - 1);
		DualPivotQuickSort(array, partitionIndices[0] + 1, partitionIndices[1] - 1);
		DualPivotQuickSort(array, partitionIndices[1] + 1, right);
    }
}

int main() {
    int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) == 1) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    DualPivotQuickSort(array, 0, arraySize - 1);
    for(int i = 0; i < arraySize; ++i) {
        if(i > 0)
            fputs(", ", stdout);
        printf("%d", array[i]);
    }
    putchar('\n');
    free(array);
    return 0;
}
