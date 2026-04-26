#include <bits/stdc++.h>
using namespace std;

long maxSubArraySum(vector<long> array) {
    int ans = array[0], temp = array[0];
    for(int i = 1; i < array.size(); ++i) {
        temp = max(array[i], temp + array[i]);
        ans = max(ans, temp);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<long> array;
    long x;
    while(cin >> x)
        array.push_back(x);
    cout << "Max subarray sum of [";
    for(int i = 0; i < array.size() - 1; ++i)
        cout << array[i] << ", ";
    cout << array.back() << "]: " << maxSubArraySum(array);
    return 0;
}
