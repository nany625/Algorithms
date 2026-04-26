#include <bits/stdc++.h>
using namespace std;

const int MAXV = 100;
vector<int> parent(MAXV), ranks(MAXV);
vector<tuple<int, int, int>> edge;

void init(int V) {
    iota(parent.begin(), parent.begin() + V, 0);
    fill(ranks.begin(), ranks.begin() + V, 0);
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

void kruskal(int V, int E) {
    init(V);
    sort(edge.begin(), edge.end(), [](auto &a, auto &b) {
        return get<2>(a) < get<2>(b);
    });
    cout << "Edges in the Minimum Spanning Tree:\n";
    int mstWeight = 0, edgeCountInMST = 0;
    for(auto [u, v, w] : edge) {
        if(find(u) != find(v)) {
            unite(u, v);
            mstWeight += w;
            ++edgeCountInMST;
            cout << "Edge (" << u << ", " << v << ") with weight " << w << '\n';
        }
        if(edgeCountInMST == V - 1)
            break;
    }
    cout << "Total weight of MST: " << mstWeight << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(u, v, w);
    }
    kruskal(V, E);
    return 0;
}

/*
Input:
5 7
0 1 2
0 3 6
1 3 8
1 2 3
1 4 5
2 4 7
3 4 9

Output:
Edges in the Minimum Spanning Tree:
Edge (0, 1) with weight 2
Edge (1, 2) with weight 3
Edge (1, 4) with weight 5
Edge (0, 3) with weight 6
Total weight of MST: 16
*/
