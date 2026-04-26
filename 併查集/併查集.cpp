#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 1000;
vector<int> parent(MAX_NUM), ranks(MAX_NUM);

void init() {
    iota(parent.begin(), parent.end(), 0);
    fill(ranks.begin(), ranks.end(), 0);
}

int find(int x) {
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        if(ranks[x] > ranks[y])
            parent[y] = x;
        else if(ranks[x] < ranks[y])
            parent[x] = y;
        else
            ++ranks[parent[y] = x];
    }
}

bool isConnected(int x, int y) {
    return find(x) == find(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int x, y;
    while(cin >> x >> y) {
        cout << x << " and " << y << " is " << (isConnected(x, y) ? "connected\n" : "disconnected\n");
        unite(x, y);
    }
    return 0;
}
