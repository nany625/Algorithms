#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int *array, int arraySize) {
    bool sorted = false;
    for(int i = 0; i < arraySize - 1 && !sorted; ++i) {
        sorted = true;
        for(int j = 0; j < arraySize - 1 - i; ++j) {
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                sorted = false;
            }
        }
    }
}

int main() {
    int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) == 1) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    BubbleSort(array, arraySize);
    for(int i = 0; i < arraySize; ++i) {
        if(i > 0)
            fputs(", ", stdout);
        printf("%d", array[i]);
    }
    putchar('\n');
    free(array);
    return 0;
}
