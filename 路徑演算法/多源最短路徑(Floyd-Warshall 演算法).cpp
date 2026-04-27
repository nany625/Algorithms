#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXV = 100;
vector<vector<int>> dist(MAXV, vector<int>(MAXV)), nxt(MAXV, vector<int>(MAXV));

void floydWarshall(int V) {
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}

void printPath(int u, int v) {
    if(dist[u][v] == INF) {
        cout << "No path";
        return;
    }
    cout << u;
    while(u != v) {
        u = nxt[u][v];
        cout << " -> " << u;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, E;
    while(cin >> V >> E) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j)
                dist[i][j] = i == j ? 0 : INF;
        }
        while(E--) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = w;
            nxt[u][v] = v;
            /* 若是無向圖，加上
            dist[v][u] = w;
            dist[v][u] = u;
            */
        }
        floydWarshall(V);
        cout << "Shortest distance matrix:\n";
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(j > 0)
                    cout << ' ';
                if(dist[i][j] == INF)
                    cout << "INF";
                else
                    cout << dist[i][j];
            }
            cout << '\n';
        }
        cout << "\nShortest paths:\n";
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if (i != j) {
                    cout << "Path from " << i << " to " << j << ": ";
                    printPath(i, j);
                }
            }
        }
    }
    return 0;
}

/*
Input:
4 4
0 1 5
1 2 3
2 3 1
0 3 10

Output:
Shortest distance matrix:
0 5 8 9 
INF 0 3 4 
INF INF 0 1 
INF INF INF 0 

Shortest paths:
Path from 0 to 1: 0 -> 1
Path from 0 to 2: 0 -> 1 -> 2
Path from 0 to 3: 0 -> 1 -> 2 -> 3
Path from 1 to 0: No path
Path from 1 to 2: 1 -> 2
Path from 1 to 3: 1 -> 2 -> 3
Path from 2 to 0: No path
Path from 2 to 1: No path
Path from 2 to 3: 2 -> 3
Path from 3 to 0: No path
Path from 3 to 1: No path
Path from 3 to 2: No path
*/
