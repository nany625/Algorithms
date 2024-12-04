#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[MAX_NUM + 1] = {true, true};
int *primes, primeCount;

void eratosthenesSieve() {
    int limit = sqrt(MAX_NUM);
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(!isComposite[n]) {
            primes = (int*)realloc(primes, (primeCount + 1) * sizeof(int));
            primes[primeCount++] = n;
            if(n <= limit) {
                for(int i = n * n; i <= MAX_NUM; i += n)
                    isComposite[i] = true;
            }
        }
    }
}

int main() {
    eratosthenesSieve();
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d is %sprime\n", n, !isComposite[n] ? "" : "not ");
    free(primes);
    return 0;
}
