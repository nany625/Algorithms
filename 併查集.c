#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 10

int parent[MAX_NUM], rank[MAX_NUM];

void init() {
    for(int n = 0; n < MAX_NUM; ++n)
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

bool isConnected(int x, int y) {
    return find(x) == find(y);
}

int main() {
    init();
    int x, y;
    while(scanf("%d %d", &x, &y) == 2) {
        printf("%d is %sconnected to %d\n", x, isConnected(x, y) ? "" : "not ", y);
        unite(x, y);
    }
    return 0;
}

/*
Input:
5 6
2 1
7 6
3 8
4 8
4 7
4 6
8 8
6 5
8 7

Output:
5 is not connected to 6
2 is not connected to 1
7 is not connected to 6
3 is not connected to 8
4 is not connected to 8
4 is not connected to 7
4 is connected to 6
8 is connected to 8
6 is connected to 5
8 is connected to 7
*/
