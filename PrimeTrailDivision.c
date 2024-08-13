#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000000

int *primes = (int*)malloc(sizeof(int)), primeCount;

bool isPrime(int n) {
    int limit = sqrt(n);
    for(int i = 0; i < primeCount && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

void init() {
    primes[0] = 2;
    primeCount = 1;
    for(int n = 3; n < MAX_NUM; n += 2) {
        if(isPrime(n)) {
            primes = (int*)realloc(primes, (primeCount + 1) * sizeof(int));
            primes[primeCount++] = n;
        }
    }
}

int main() {
    init();
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d is %sprime.\n", n, isPrime(n) ? "" : "not ");
    free(primes);
    return 0;
}
