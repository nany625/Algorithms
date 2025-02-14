#include <stdio.h>

int josephus(int n, int k) {
    int ans = 0;
    for(int i = 2; i <= n; ++i)
        ans = (ans + k) % i;
    return ans;
}

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
        printf("The last person standing is at position %d\n", josephus(n, k) + 1);
    return 0;
}
