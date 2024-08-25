#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FIBONACCI_SIZE 10000

typedef struct {
    char *number;
    short digits;
} BigNumber;

BigNumber fib[MAX_FIBONACCI_SIZE + 1];

void initFibonacci() {
    fib[0].number = strdup("0");
    fib[1].number = strdup("1");
    fib[0].digits = fib[1].digits = 1;
    for(int i = 2; i <= MAX_FIBONACCI_SIZE; ++i) {
        fib[i].number = (char*)malloc((fib[i - 1].digits + 1) * sizeof(char));
        memset(fib[i].number, '0', fib[i - 1].digits + 1);
        short j;
        for(j = 0; j < fib[i - 1].digits; ++j) {
        	fib[i].number[j + 1] += (fib[i].number[j] + fib[i - 1].number[j] + fib[i - 2].number[j] - 3 * '0') / 10;
        	fib[i].number[j] = (fib[i].number[j] + fib[i - 1].number[j] + fib[i - 2].number[j] - 3 * '0') % 10 + '0';
        }
        fib[i].digits = j + (fib[i].number[j] - '0');
    }
}

int main() {
    initFibonacci();
    int n;
    while(scanf("%d", &n) == 1) {
        printf("The Fibonacci number for %d is ", n);
        for(int i = fib[n].digits - 1; i >= 0; --i)
            putchar(fib[n].number[i]);
        putchar('\n');
    }
    for(int i = 0; i <= MAX_FIBONACCI_SIZE; ++i)
        free(fib[i].number);
    return 0;
}

/*
Input:
0
1
2
3
4
5
10
20
50
100
1000

Output:
The Fibonacci number for 0 is 0
The Fibonacci number for 1 is 1
The Fibonacci number for 2 is 1
The Fibonacci number for 3 is 2
The Fibonacci number for 4 is 3
The Fibonacci number for 5 is 5
The Fibonacci number for 10 is 55
The Fibonacci number for 20 is 6765
The Fibonacci number for 50 is 12586269025
The Fibonacci number for 100 is 354224848179261915075
The Fibonacci number for 1000 is 43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875
*/
