#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
vector<vector<pair<int, int>>> adj(MAXN);
vector<int> indeg(MAXN);

vector<int> topo_sort(int V) {
    queue<int> q;
    for(int i = 0; i < V; ++i) {
        if(indeg[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto [v, w] : adj[u]) {
            if(--indeg[v] == 0)
                q.push(v);
        }
        topo.push_back(u);
    }
    if(topo.size() != n)
        return {};
    return topo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, E;
    while(cin >> V >> E) {
        for(int i = 0; i < V; ++i)
            adj[i].clear();
        fill(indeg.begin(), indeg.begin() + V, 0);
        while(E--) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            ++indeg[v];
        }
        vector<int> topo = topo_sort(V);
        for(int i = 0; i < topo.size() - 1; ++i)
            cout << topo[i] << ' ';
        cout << topo.back() << '\n';
    }
    return 0;
}
