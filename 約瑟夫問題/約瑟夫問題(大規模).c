#include <stdio.h>

long josephus(long n, long k) {
    if(n == 1)
        return 0;
    if(k == 1)
        return n - 1;
    if(k > n)
        return (josephus(n - 1, k) + k) % n;
    long ans = josephus(n - n / k, k);
    ans -= n % k;
    if(ans < 0)
        ans += n;
    else
        ans += ans / (k - 1);
    return ans;
}

int main() {
    long n, k;
    while(scanf("%ld %ld", &n, &k) == 2)
        printf("The last person standing is at position %ld\n", josephus(n, k) + 1);
	return 0;
}
