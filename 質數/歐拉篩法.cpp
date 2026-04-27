#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 10000000;
bitset<(MAX_NUM >> 1) + 1> mark;
vector<int> primes;

void eulerSieve() {
    mark[0] = 1;
    primes.push_back(2);
    for(int n = 3; n <= MAX_NUM; n += 2) {
        if(!mark[n >> 1])
            primes.push_back(n);
        for(int i = 1, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            mark[temp >> 1];
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eulerSieve();
    int n;
    while(cin >> n)
        cout << n << (n == 2 || (n & 1 && !mark[n >> 1]) ? " is prime\n" : " is not prime\n"); 
    return 0;
}
