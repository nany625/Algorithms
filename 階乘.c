#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FACTORIAL_SIZE 1000

typedef struct {
    char *number;
    short digits;
} BigNumber;

BigNumber fac[MAX_FACTORIAL_SIZE + 1];
char temp[5];

void initFactorial() {
	fac[0].number = strdup("0");
	fac[1].number = strdup("1");
    fac[0].digits = fac[1].digits = 1;
    for(int i = 2; i <= MAX_FACTORIAL_SIZE; ++i) {
        sprintf(temp, "%d", i);
        int len = strlen(temp);
        fac[i].number = (char*)malloc((fac[i - 1].digits + len + 1) * sizeof(char));
        memset(fac[i].number, '0', (fac[i - 1].digits + len) * sizeof(char));
        fac[i].number[fac[i - 1].digits + len] = '\0';
        for(int j = len - 1; j >= 0; --j) {
            for(int k = 0; k < fac[i - 1].digits; ++k) {
                fac[i].number[len - j + k] += ((fac[i - 1].number[k] - '0') * (temp[j] - '0') + fac[i].number[len - 1 - j + k] - '0') / 10;
                fac[i].number[len - 1 - j + k] = ((fac[i - 1].number[k] - '0') * (temp[j] - '0') + fac[i].number[len - 1 - j + k] - '0') % 10 + '0';
            }
        }
        fac[i].digits = fac[i - 1].digits + len - (fac[i].number[fac[i - 1].digits + len - 1] == '0');
    }
}

int main() {
    initFactorial();
    int n;
    while(scanf("%d", &n) == 1) {
        printf("%d! = ", n);
        for(int i = fac[n].digits - 1; i >= 0; --i)
            putchar(fac[n].number[i]);
        putchar('\n');
    }
    for(int i = 0; i <= MAX_FACTORIAL_SIZE; ++i)
        free(fac[i].number);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_FACTORIAL_SIZE 1000

typedef struct {
    char *number;
    short digits;
} BigNumber;

BigNumber fac[MAX_FACTORIAL_SIZE + 1];

void initFactorial() {
	fac[0].number = strdup("0");
	fac[1].number = strdup("1");
    fac[0].digits = fac[1].digits = 1;
    char *temp = NULL;
    for(int i = 2; i <= MAX_FACTORIAL_SIZE; ++i) {
        int len = log10(i) + 1;
        temp = (char*)malloc((len + 1) * sizeof(char));
        sprintf(temp, "%d", i);
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
        printf("%d!\n%s\n", n, fac[n].number);
    for(int i = 0; i <= MAX_FACTORIAL_SIZE; ++i)
        free(fac[i].number);
    return 0;
}
