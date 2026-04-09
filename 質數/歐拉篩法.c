#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 6) + 1];
int *primes, size = 1;

void eulerSieve() {
    SET(0);
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

int main() {
    eulerSieve();
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d is %sprime\n", n, n == 2 || (n & 1 && !GET(n >> 1)) ? "" : "not ");
    free(primes);
    return 0;
}
