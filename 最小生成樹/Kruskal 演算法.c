#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define MAXE 10000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAXE];
int parent[MAXV], rank[MAXV];

void init(int V) {
    for(int n = 0; n < V; ++n)
        rank[parent[n] = n] = 0;
}

int find(int x) {
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if(rootX != rootY) {
        if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
            ++rank[parent[rootY] = rootX];
    }
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w > ((Edge*)b)->w;
}

void kruskal(int V, int E) {
    init(V);
    qsort(edges, E, sizeof(Edge), compare);
    int mstWeight = 0, edgeCountInMST = 0;
    puts("Edges in the Minimum Spanning Tree:");
    for(int i = 0; i < E && edgeCountInMST < V - 1; ++i) {
        if(find(edges[i].u) != find(edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            mstWeight += edges[i].w;
            ++edgeCountInMST;
            printf("Edge (%d, %d) with weight %d\n", edges[i].u, edges[i].v, edges[i].w);
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
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
