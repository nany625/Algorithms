#include <stdio.h>

long temp[2][2];

void multiplyMatrix(long a[2][2], long b[2][2], int mod) {
    temp[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    temp[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    temp[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    temp[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    a[0][0] = temp[0][0];
    a[0][1] = temp[0][1];
    a[1][0] = temp[1][0];
    a[1][1] = temp[1][1];
}

int powerMatrix(long matrix[2][2], int n, int mod) {
    long result[2][2] = {{1, 0}, {0, 1}};
    while(n > 0) {
        if(n & 1)
            multiplyMatrix(result, matrix, mod);
        multiplyMatrix(matrix, matrix, mod);
        n >>= 1;
    }
    return result[0][0];
}

int main() {
    int n, mod;
    while(scanf("%d %d", &n, &mod) == 2) {
        if(n <= 1) {
            printf("F(%d) %% %d = %d\n", n, mod, n == 1 && mod != 1);
            continue;
        }
        long matrix[2][2] = {{1, 1}, {1, 0}};
        printf("F(%d) %% %d = %d\n", n, mod, powerMatrix(matrix, n - 1, mod));
    }
    return 0;
}
