#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 1000000;
bitset<MAX_NUM + 1> mark;

void eratosthenesSieve() {
    mark[0] = mark[1] = 1;
    int limit = sqrt(MAX_NUM);
    for(int n = 2; n <= limit; ++n) {
        if(!mark[n]) {
            for(int i = n * n; i <= MAX_NUM; i += n)
                mark[i] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eratosthenesSieve();
    int n;
    while(cin >> n)
        cout << n << (!mark[n] ? " is prime\n" : " is not prime\n"); 
    return 0;
}
