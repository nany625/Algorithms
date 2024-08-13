#include <stdio.h>

long GCD(long a, long b) {
    return b == 0 ? a : GCD(b, a % b);
}

int main() {
    long a, b;
    while(scanf("%ld %ld", &a, &b) && a != 0 && b != 0)
        printf("GCD of %ld and %ld is %ld.\n", a, b, GCD(a, b));
    return 0;
}
