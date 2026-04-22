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
    for(int i = sequence.size() - 1; i >= 0; --i) {
        int pos = lower_bound(tail.begin(), tail.end(), sequence[i], greater<int>()) - tail.begin();
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
    int first = tailIdx.back();
    do {
        LIS.push_back(sequence[first]);
        first = pre[first];
    } while(first != -1);
    cout << "Length of LIS of [";
    for(int i = 0; i < sequence.size() - 1; ++i)
        cout << sequence[i] << ", ";
    cout << sequence.back() << "] is " << tail.size() << '\n';
    cout << "The first occurrence LIS is [";
    for(int i = 0; i < LIS.size() - 1; ++i)
        cout << LIS[i] << ", ";
    cout << LIS.back() << "]\n";
    return 0;
}
