#include <stdio.h>

int josephus(int n, int k) {
    return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
        printf("The last person standing is at position %d\n", josephus(n, k) + 1);
	return 0;
}
