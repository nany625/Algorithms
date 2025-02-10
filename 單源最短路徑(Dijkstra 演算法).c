#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXV 1000
#define INF INT_MAX

typedef struct {
    int next, weight;
} Edge;

Edge **graph;
int edgeCount[MAXV], dist[MAXV], prev[MAXV], stack[MAXV];
bool visited[MAXV];

int findMinDistance(int n) {
    int minDist = INF, minIndex = -1;
    for(int i = 0; i < n; ++i) {
        if(!visited[i] && dist[i] < minDist)
            minDist = dist[minIndex = i];
    }
    return minIndex;
}

void printPath(int start, int end) {
    int top = 0;
    while(end != start) {
        stack[top++] = end;
        end = prev[end];
    }
    printf("%d", start);
    while(top--)
        printf(" -> %d", stack[top]);
    putchar('\n');
}

void dijkstra(int start, int n) {
    for(int i = 0; i < n; ++i) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    for(int i = 0; i < n - 1; ++i) {
        int u = findMinDistance(n);
        if(u == -1)
            break;
        visited[u] = 1;
        for(int j = 0; j < edgeCount[u]; ++j) {
            if(!visited[graph[u][j].next] && dist[u] + graph[u][j].weight < dist[graph[u][j].next]) {
                dist[graph[u][j].next] = dist[u] + graph[u][j].weight;
                prev[graph[u][j].next] = u;
            }
        }
    }
    printf("Shorted distance from node %d to other nodes:\n", start);
    for(int i = 0; i < n; ++i) {
        if(dist[i] == INF)
            printf("to node %d: impossible\n", i);
        else {
            printf("to node %d: %d\n", i, dist[i]);
            printPath(start, i);
        }
    }
}

int main() {
    graph = (Edge**)malloc(MAXV * sizeof(Edge*));
    for(int i = 0; i < MAXV; ++i)
        graph[i] = NULL;
    int n, m;   // 節點數和邊數
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u] = (Edge*)realloc(graph[u], (edgeCount[u] + 1) * sizeof(Edge));
        graph[u][edgeCount[u]].next = v;
        graph[u][edgeCount[u]++].weight = w;    // 有向圖
        /* 若是無向圖，加上
        graph[v] = (Edge*)realloc(graph[v], (edgeCount[v] + 1) * sizeof(Edge));
        graph[v][edgeCount[v]].next = u;
        graph[v][edgeCount[v]++].weight = w;    */
    }
    int start;
    while(scanf("%d", &start) == 1)
        dijkstra(start, n);
    for(int i = 0; i < MAXV; ++i)
        free(graph[i]);
    free(graph);
    return 0;
}

/*
Input:
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
5 4 10
6 5 2
6 8 6
7 6 1
7 8 7
0
1
2

Output:
Shorted distance from node 0 to other nodes:
to node 0: 0
0
to node 1: 4
0 -> 1
to node 2: 12
0 -> 1 -> 2
to node 3: 19
0 -> 1 -> 2 -> 3
to node 4: 21
0 -> 7 -> 6 -> 5 -> 4
to node 5: 11
0 -> 7 -> 6 -> 5
to node 6: 9
0 -> 7 -> 6
to node 7: 8
0 -> 7
to node 8: 14
0 -> 1 -> 2 -> 8
Shorted distance from node 1 to other nodes:
to node 0: impossible
to node 1: 0
1
to node 2: 8
1 -> 2
to node 3: 15
1 -> 2 -> 3
to node 4: 22
1 -> 2 -> 5 -> 4
to node 5: 12
1 -> 2 -> 5
to node 6: 12
1 -> 7 -> 6
to node 7: 11
1 -> 7
to node 8: 10
1 -> 2 -> 8
Shorted distance from node 2 to other nodes:
to node 0: impossible
to node 1: impossible
to node 2: 0
2
to node 3: 7
2 -> 3
to node 4: 14
2 -> 5 -> 4
to node 5: 4
2 -> 5
to node 6: impossible
to node 7: impossible
to node 8: 2
2 -> 8
*/
