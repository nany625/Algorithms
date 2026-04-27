#include <bits/stdc++.h>
using namespace std;

bool sexyPrime(int n) {
    if(n <= 3)
        return n > 1;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    int limit = sqrt(n);
    for(int i = 5; i <= limit; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n)
        cout << n << (sexyPrime(n) ? " is prime\n" : " is not prime\n"); 
    return 0;
}
