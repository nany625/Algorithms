#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[MAX_NUM + 1] = {true, true};
int *primes, size;

void eulerSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(!isComposite[i]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 0, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    eulerSieve();
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d is %sprime\n", n, !isComposite[n] ? "" : "not ");
    free(primes);
    return 0;
}
