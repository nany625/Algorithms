#include <stdio.h>
#include <math.h>
#define MAX_NUM 1000000
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 5) + 1];
bool isComposite[MAX_NUM + 1] = {true, true};

void eratosthenesSieve() {
    SET(0);
    SET(1);
    int limit = sqrt(MAX_NUM);
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(n <= limit && !GET(n)) {
            for(int i = n * n; i <= MAX_NUM; i += n)
                SET(i);
        }
    }
}

int main() {
    eratosthenesSieve();
    int n;
    while(scanf("%d", &n) && n != 0)
        printf("%d is %sprime\n", n, !GET(n) ? "" : "not ");
    return 0;
}
