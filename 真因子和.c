#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[MAX_NUM + 1] = {true, true, false};
int *primes = (int*)malloc(sizeof(int)), primeCount;

void sieve() {
    primes[0] = 2;
    primeCount = 1;
    int limit = sqrt(MAX_NUM);
    for(int n = 3; n <= MAX_NUM; n += 2) {
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

long trueFactorSum(long n) {
    long sum = 1, limit = sqrt(n), temp = n;
    for(int i = 0; i < primeCount && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            long tempSum = 1, term = 1;
            do {
                tempSum += term *= primes[i];
                n /= primes[i];
            } while(n % primes[i] == 0);
            sum *= tempSum;
            limit = sqrt(n);
        }
    }
    if(n > 1)
        sum *= (1 + n);
    return sum - temp;
}

int main() {
    sieve();
    long n;
    while(scanf("%ld", &n) && n != 0)
        printf("Sum of divisors of %ld is %ld.\n", n, trueFactorSum(n));
    free(primes);
    return 0;
}
