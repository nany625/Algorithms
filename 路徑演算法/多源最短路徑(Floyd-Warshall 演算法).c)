#include <stdio.h>
#include <limits.h>
#define INF 1e9
#define MAXV 100

int dist[MAXV][MAXV], next[MAXV][MAXV];

void floydWarshall(int V) {
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printPath(int u, int v) {
    if(dist[u][v] == INF) {
        puts("No path");
        return;
    }
    printf("%d", u);
    while(u != v) {
        u = next[u][v];
        printf(" -> %d", u);
    }
    putchar('\n');
}

int main() {
    int V, E;
    while(scanf("%d %d", &V, &E) == 2) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j)
                dist[i][j] = i == j ? 0 : INF;
        }
        while(E--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            dist[u][v] = w;
            next[u][v] = v;
            /* 若是無向圖，加上
            dist[v][u] = w;
            dist[v][u] = u;
            */
        }
        floydWarshall(V);
        puts("Shortest distance matrix:");
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(j > 0)
                    putchar(' ');
                if(dist[i][j] == INF)
                    fputs("INF", stdout);
                else
                    printf("%d", dist[i][j]);
            }
            putchar('\n');
        }
        puts("\nShortest paths:");
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if (i != j) {
                    printf("Path from %d to %d: ", i, j);
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
