#include <bits/stdc++.h>
using namespace std;

vector<int> sequence;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n)
        sequence.push_back(n);
    vector<int> tail, tailIdx, pre(sequence.size(), -1);
    for(int i = 0; i < sequence.size(); ++i) {
        int pos = lower_bound(tail.begin(), tail.end(), sequence[i]) - tail.begin();
        if(pos == tail.size()) {
            tail.push_back(sequence[i]);
            tailIdx.push_back(i);
        } else {
            tail[pos] = sequence[i];
            tailIdx[pos] = i;
        }
        if(pos > 0)
            pre[i] = tailIdx[pos - 1];
    }
    vector<int> LIS;
    int last = tailIdx.back();
    while(last != -1) {
        LIS.push_back(sequence[last]);
        last = pre[last];
    }
    reverse(LIS.begin(), LIS.end());
    cout << "Length of LIS of [";
    for(int i = 0; i < sequence.size() - 1; ++i)
        cout << sequence[i] << ", ";
    cout << sequence.back() << "] is " << tail.size() << '\n';
    cout << "The last occurrence LIS is [";
    for(int i = 0; i < LIS.size() - 1; ++i)
        cout << LIS[i] << ", ";
    cout << LIS.back() << "]\n";
    return 0;
}
