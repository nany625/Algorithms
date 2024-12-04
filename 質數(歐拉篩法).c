#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[MAX_NUM + 1] = {true, true};
int *primes, size;

int main() {
    for(int i = 2; i <= MAX_NUM; ++i) {
        if(!isComposite[i]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = i;
        }
        for(int j = 0, temp; j < size && (temp = primes[j] * i) <= MAX_NUM; ++j) {
            isComposite[temp] = true;
            if(i % primes[j] == 0)
                break;
        }
    }
    free(primes);
    return 0;
}
