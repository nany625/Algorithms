#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_FACTORIAL_SIZE 1000

typedef struct {
    char *number;
    short digits;
} BigNumber;

BigNumber fac[MAX_FACTORIAL_SIZE];

void initFactorial() {
	fac[0].number = strdup("1");
    fac[0].digits = 1;
    char *temp = NULL;
    for(int i = 1; i < MAX_FACTORIAL_SIZE; ++i) {
        int len = log10(i + 1) + 1;
        temp = (char*)malloc((len + 1) * sizeof(char));
        sprintf(temp, "%d", i + 1);
        fac[i].number = (char*)malloc((fac[i - 1].digits + len + 1) * sizeof(char));
        memset(fac[i].number, '0', (fac[i - 1].digits + len) * sizeof(char));
        fac[i].number[fac[i - 1].digits + len] = '\0';
        for(int j = len - 1; j >= 0; --j) {
            for(int k = fac[i - 1].digits - 1; k >= 0; --k) {
                fac[i].number[j + k] += ((fac[i - 1].number[k] - '0') * (temp[j] - '0') + fac[i].number[j + k + 1] - '0') / 10;
                fac[i].number[j + k + 1] = ((fac[i - 1].number[k] - '0') * (temp[j] - '0') + fac[i].number[j + k + 1] - '0') % 10 + '0';
            }
        }
        int j = 0;
        while(fac[i].number[j] == '0')
            ++j;
        fac[i].digits = fac[i - 1].digits + len - j;
        memmove(fac[i].number, fac[i].number + j, fac[i].digits * sizeof(char));
        fac[i].number[fac[i].digits] = '\0';
        free(temp);
    }
}

int main() {
    initFactorial();
    int n;
    while(scanf("%d", &n) == 1)
        printf("%d! = %s\n", n, fac[n - 1].number);
    for(int i = 0; i < MAX_FACTORIAL_SIZE; ++i)
        free(fac[i].number);
    return 0;
}
