#include <bits/stdc++.h>
using namespace std;

const int MAXV = 10000;
array<vector<pair<int, int>>, MAXV> adj;
array<int, MAXV> dist, pre;

void dijkstra(int V, int S, int T) {
    // 優先佇列，儲存已訪問之節點與最短距離，以距離由小到大排列
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // 初始化距離為無窮大
    fill(dist.begin(), dist.end(), INT_MAX);
    // 初始化前驅節點為自己
    iota(pre.begin(), pre.end(), 0);
    // 與自己(起點)距離為0
    dist[S] = 0;
    // 將自己加入優先佇列
    pq.emplace(0, S);
    do {
        auto [d, u] = pq.top();
        /* 若只需要S到T的距離，可提早終止
        if(u == T)
            break;*/
        pq.pop();
        // 若d比已知最短距離大，表示此距離為舊的，直接跳過
        if(d > dist[u])
            continue;
        for(auto [v, w] : adj[u]) {
            // 若可鬆弛，更新距離及前驅節點，並且加入優先佇列
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
                pre[v] = u;
            }
        }
    } while(!pq.empty());
    if(dist[T] == INT_MAX)
        cout << S << " can't reach " << T << '\n';
    else {
        cout << "Shortest path from " << S << " to " << T << ": ";
        vector<int> path;
        // 反向回溯路徑
        while(T != S) {
            path.push_back(T);
            T = pre[T];
        }
        path.push_back(S);
        for(int i = path.size() - 1; i > 0; --i)
            cout << path[i] << " -> ";
        cout << path.front() << ", distance is " << dist[path.front()] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // V:節點數，E:邊數
    int V, E;
    cin >> V >> E;
    // 初始化鄰接表
    for(int i = 0; i < V; ++i)
        adj[i].clear();
    while(E--) {
        // u:起點，v:終點，w:邊權
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        /* 若是無向圖，加上
        adj[v].emplace_back(u, w);
        */
    }
    int Q;
    cin >> Q;
    while(Q--) {
        // s:起點，t:終點
        int s, t;
        cin >> s >> t;
        dijkstra(V, s, t);
    }
    return 0;
}

/*
Input:
9 15
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 7 7
5 4 10
6 5 2
6 8 6
7 6 1
7 8 7
5
0 4
1 6
2 0
3 6
5 8

Output:
Shortest path from 0 to 4: 0 -> 7 -> 6 -> 5 -> 4, distance is 21
Shortest path from 1 to 6: 1 -> 7 -> 6, distance is 12
2 can't reach 0
Shortest path from 3 to 6: 3 -> 4 -> 7 -> 6, distance is 17
Shortest path from 5 to 8: 5 -> 4 -> 7 -> 8, distance is 24
*/
