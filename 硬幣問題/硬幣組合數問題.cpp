#include <bits/stdc++.h>
using namespace std;

const int MAX_TARGET = 100000;
vector<long> dp(MAX_TARGET + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> coins;
    int x;
    while(cin >> x && x != 0)
        coins.push_back(x);
    dp[0] = 1;
    for(int x : coins) {
        for(int i = x; i <= MAX_TARGET; ++i)
            dp[i] += dp[i - x];
    }
    int target;
    while(cin >> target)
        cout << "Number of combinations to make $" << target << ": " << dp[target] << '\n'; 
    return 0;
}

/*
Input:
1 2 5 10 20 50 0
0
1
2
3
5
25
100
325
1000
3000
8000
10000
50000
100000

Output:
Number of combinations to make $0: 1
Number of combinations to make $1: 1
Number of combinations to make $2: 2
Number of combinations to make $3: 2
Number of combinations to make $5: 4
Number of combinations to make $25: 68
Number of combinations to make $100: 4562
Number of combinations to make $325: 559632
Number of combinations to make $1000: 103119386
Number of combinations to make $3000: 21773421656
Number of combinations to make $8000: 2806483881081
Number of combinations to make $10000: 8518079396351
Number of combinations to make $50000: 26156426151481751
Number of combinations to make $100000: 835168075439213501
*/
