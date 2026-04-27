#include <bits/stdc++.h>
using namespace std;

int levenshteinDistance(string x, string y) {
    vector<int> dp(y.length() + 1);
    iota(dp.begin(), dp.end(), 0);
    for(int i = 1; i <= x.length(); ++i) {
        int prev = dp[0];
        dp[0] = i;
        for(int j = 1; j <= y.length(); ++j) {
            int temp = dp[j];
            if(x[i - 1] == y[j - 1])
                dp[j] = prev;
            else
                dp[j] = 1 + min({dp[j], dp[j - 1], prev});
            prev = temp;
        }
    }
    return dp.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x, y;
    while(cin >> x >> y)
        cout << "The Levenshtein distance between \"" << x << "\" and \"" << y << "\": " << levenshteinDistance(x, y) << '\n';
    return 0;
}

/*
Input:
romantic domino
kitten sitting

Output:
The Levenshtein distance between "romantic" and "domino": 5
The Levenshtein distance between "kitten" and "sitting": 3
*/
