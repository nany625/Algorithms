#include <stdio.h>

long bigMod(long base, long power, int mod) {
    if(power == 0)
        return 1 % mod;
    if(power == 1)
        return base % mod;
    long temp = bigMod(base, power >> 1, mod);
    if(power & 1)
        return temp * temp % mod * base % mod;
    return temp * temp % mod;
}

int main() {
    long base, power;
    int mod;
    while(scanf("%ld %ld %d", &base, &power, &mod) == 3)
        printf("%ld^%ld %% %d = %ld\n", base, power, mod, bigMod(base, power, mod));
	return 0;
}
