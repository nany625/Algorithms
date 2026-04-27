#include <bits/stdc++.h>
using namespace std;

const int MAX_AMOUNT = 10000;
vector<int> dp(MAX_AMOUNT + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> coins;
    int x;
    while(cin >> x && x != 0)
        coins.push_back(x);
    for(int i = 1; i <= MAX_AMOUNT; ++i) {
        dp[i] = MAX_AMOUNT + 1;
        for(int x : coins) {
            if(i >= x)
                dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    int amount;
    while(cin >> amount) {
        if(dp[amount] <= MAX_AMOUNT)
            cout << "Minimum coins required to make $" << amount << ": " << dp[amount] << '\n';
        else
            cout << "It's not possible to make $" << amount << " with the given coins.\n";
    }
    return 0;
}

/*
Input:
3 5 10 12 20 50 100 180 500 1000 0
0
1
2
5
15
25
80
120
190
720
1350
3700
6666
10000

Ouptut:
Minimum coins required to make $0: 0
It's not possible to make $1 with the given coins.
It's not possible to make $2 with the given coins.
Minimum coins required to make $5: 1
Minimum coins required to make $15: 2
Minimum coins required to make $25: 2
Minimum coins required to make $80: 3
Minimum coins required to make $120: 2
Minimum coins required to make $190: 2
Minimum coins required to make $720: 4
Minimum coins required to make $1350: 5
Minimum coins required to make $3700: 6
Minimum coins required to make $6666: 12
Minimum coins required to make $10000: 10
*/
