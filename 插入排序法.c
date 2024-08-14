#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *array, int arraySize) {
    for(int i = 1; i < arraySize; ++i) {
        int j = i - 1, insertionNum = array[i];
        while(j >= 0 && insertionNum < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionNum;
    }
}

int main() {
    int *array = NULL, arraySize = 0, n;
    while(scanf("%d", &n) == 1) {
        array = (int*)realloc(array, (arraySize + 1) * sizeof(int));
        array[arraySize++] = n;
    }
    InsertionSort(array, arraySize);
    for(int i = 0; i < arraySize; ++i) {
        if(i > 0)
            fputs(", ", stdout);
        printf("%d", array[i]);
    }
    putchar('\n');
    free(array);
    return 0;
}
