#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NUM 1000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
int *primes, size = 1;

void eulerSieve() {
    primes = (int*)realloc(primes, sizeof(int));
    primes[0] = 2;
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!GET(n >> 1)) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            SET(temp >> 1);
            if(n % primes[i] == 0)
                break;
        }
    }
}

long trueFactorSum(long n) {
    long sum = 1, limit = sqrt(n), temp = n;
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
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
    eulerSieve();
    long n;
    while(scanf("%ld", &n) && n != 0)
        printf("Sum of true factors of %ld: %ld\n", n, trueFactorSum(n));
    free(primes);
    return 0;
}
