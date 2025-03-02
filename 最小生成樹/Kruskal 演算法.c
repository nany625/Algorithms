#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define MAXE 10000

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAXE];
int parent[MAXV];

int find(int x) {
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w > ((Edge*)b)->w;
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) == 2) {
        for(int i = 0; i < m; ++i)
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        qsort(edges, m, sizeof(Edge), compare);
        for(int i = 0; i < n; ++i)
            root[i] = i;
        long sum = 0;
        int count = 0;
        for(int i = 0; i < m && count < n - 1; ++i) {
            int root1 = find(edges[i].u), root2 = find(edges[i].v);
            if(root1 != root2) {
                sum += edges[i].w;
                root[root2] = root1;
                ++count;
            }
        }
        if(count == n - 1)
            printf("%ld\n", sum);
        else
            puts("-1");
    }
    return 0;
}
