#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXV 1000  // 最大節點數
#define INF INT_MAX

typedef struct {
    int to, weight, next;
} Edge;

Edge edges[MAXV * MAXV];
int head[MAXV], dist[MAXV], inQueue[MAXV];
int edgeCount;

void addEdge(int u, int v, int w) {
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;
}

bool spfa(int start, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        inQueue[i] = 0;
    }
    dist[start] = 0;

    int queue[MAXV], front = 0, rear = 0;
    queue[rear++] = start;
    inQueue[start] = 1;

    while (front != rear) {
        int u = queue[front++];
        if (front == MAXV) front = 0;  // 環形隊列
        inQueue[u] = 0;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to, w = edges[i].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!inQueue[v]) {
                    queue[rear++] = v;
                    if (rear == MAXV) rear = 0;  // 環形隊列
                    inQueue[v] = 1;
                }
            }
        }
    }

    return true;  // 若需要檢測負權環，需額外加入判斷。
}

int main() {
    int n, m;  // 節點數和邊數
    scanf("%d %d", &n, &m);

    edgeCount = 0;
    for (int i = 0; i < n; i++) head[i] = -1;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int start;
    scanf("%d", &start);

    if (spfa(start, n)) {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF)
                printf("Node %d: Unreachable\n", i);
            else
                printf("Node %d: %d\n", i, dist[i]);
        }
    } else {
        printf("Negative weight cycle detected.\n");
    }

    return 0;
}
