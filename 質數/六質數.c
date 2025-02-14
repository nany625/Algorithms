#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool sexyPrime(int n) {
    if(n <= 3)
        return n > 1;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    int limit = sqrt(n);
    for(int i = 5; i <= limit; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d is %sprime\n", n, sexyPrime(n) ? "" : "not ");
    return 0;
}
