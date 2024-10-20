#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int *array, int arraySize) {
    for(int i = 0; i < arraySize - 1; ++i) {
        int minIndex = i;
        for(int j = i + 1; j < arraySize; ++j) {
            if(array[minIndex] > array[j])
                minIndex = j;
        }
        swap(&array[minIndex], &array[i]);
    }
}

int main() {
    int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) == 1) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    SelectionSort(array, arraySize);
    for(int i = 0; i < arraySize - 1; ++i)
        printf("%d, ", array[i]);
    printf("%d\n", array[arraySize - 1]);
    free(array);
    return 0;
}
