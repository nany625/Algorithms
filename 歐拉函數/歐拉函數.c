// #解法一
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 1000000

bool isComposite[(MAX_NUM >> 1) + 1];
int *primes, size = 1;

void eulerSieve() {
    primes = (int*)malloc(sizeof(int));
    primes[0] = 2;
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (int*)realloc(primes, (size + 1) * sizeof(int));
            primes[size++] = n;
        }
        for(int i = 1, temp; i < size && (temp = primes[i] * n) <= MAX_NUM; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

long eulerTotient(long n) {
    if(n == 1)
        return 0;
    long ans = n, limit = sqrt(n);
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            ans -= ans / primes[i];
            do {
                n /= primes[i];
            } while(n % primes[i] == 0);
            limit = sqrt(n);
        }
    }
    if(n > 1)
        ans -= ans / n;
    return ans;
}

int main() {
    eulerSieve();
    long n;
    while(scanf("%ld", &n) && n != 0)
        printf("φ(%ld) = %ld\n", n, eulerTotient(n));    // 小於等於正整數n的所有與n互質的正整數個數
    free(primes);
	return 0;
}

// #解法二
#include <stdio.h>
#define MAX_NUM 1000000

int phi[MAX_NUM + 1];

void eratosthenesSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(phi[n] == n) {
            for(int i = n; i <= MAX_NUM; i += n)
                phi[i] -= phi[i] / n;
        }
    }
}

int main() {
    for(int n = 2; n <= MAX_NUM; ++n)
        phi[n] = n;
    eratosthenesSieve();
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("φ(%d) = %d\n", n, phi[n]);    // 小於等於正整數n的所有與n互質的正整數個數
	return 0;
}
