// #解法一
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 1000       // 最大節點數
#define INF INT_MAX     // 無窮大表示無法到達

// 鄰接表的結構定義
typedef struct Edge {
    int to;             // 鄰接節點
    int weight;         // 邊權重
    struct Edge *next;  // 下一條邊
} Edge;

typedef struct {
    Edge *head;         // 指向鄰接邊的鏈表頭
} Graph[MAXV];

// 最小堆的結構定義
typedef struct {
    int vertex;         // 節點編號
    int dist;           // 最短距離
} MinHeapNode;

typedef struct {
    MinHeapNode *nodes; // 堆中的節點
    int size;           // 堆大小
    int capacity;       // 堆容量
    int *pos;           // 記錄節點在堆中的位置
} MinHeap;

// 創建一個圖的鄰接表
void initGraph(Graph graph, int n) {
    for (int i = 0; i < n; i++) {
        graph[i].head = NULL;
    }
}

// 添加邊（鄰接表）
void addEdge(Graph graph, int u, int v, int weight) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = v;
    newEdge->weight = weight;
    newEdge->next = graph[u].head;
    graph[u].head = newEdge;
}

// 創建一個最小堆
MinHeap *createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->nodes = (MinHeapNode *)malloc(capacity * sizeof(MinHeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    heap->pos = (int *)malloc(capacity * sizeof(int));
    return heap;
}

// 最小堆的交換操作
void swapMinHeapNode(MinHeapNode *a, MinHeapNode *b) {
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// 堆化操作
void minHeapify(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->nodes[left].dist < heap->nodes[smallest].dist)
        smallest = left;
    if (right < heap->size && heap->nodes[right].dist < heap->nodes[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode smallestNode = heap->nodes[smallest];
        MinHeapNode idxNode = heap->nodes[idx];

        heap->pos[smallestNode.vertex] = idx;
        heap->pos[idxNode.vertex] = smallest;

        swapMinHeapNode(&heap->nodes[smallest], &heap->nodes[idx]);

        minHeapify(heap, smallest);
    }
}

// 提取最小距離的節點
MinHeapNode extractMin(MinHeap *heap) {
    if (heap->size == 0) {
        MinHeapNode nullNode = {-1, -1};
        return nullNode;
    }

    MinHeapNode root = heap->nodes[0];
    MinHeapNode lastNode = heap->nodes[heap->size - 1];
    heap->nodes[0] = lastNode;

    heap->pos[root.vertex] = heap->size - 1;
    heap->pos[lastNode.vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// 更新最小堆中的距離
void decreaseKey(MinHeap *heap, int vertex, int dist) {
    int i = heap->pos[vertex];
    heap->nodes[i].dist = dist;

    while (i && heap->nodes[i].dist < heap->nodes[(i - 1) / 2].dist) {
        heap->pos[heap->nodes[i].vertex] = (i - 1) / 2;
        heap->pos[heap->nodes[(i - 1) / 2].vertex] = i;
        swapMinHeapNode(&heap->nodes[i], &heap->nodes[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

// 判斷節點是否在堆中
int isInMinHeap(MinHeap *heap, int vertex) {
    return heap->pos[vertex] < heap->size;
}

// Dijkstra 演算法
void dijkstra(Graph graph, int start, int n) {
    int dist[MAXV];
    MinHeap *heap = createMinHeap(n);

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        heap->nodes[i].vertex = i;
        heap->nodes[i].dist = INF;
        heap->pos[i] = i;
    }

    dist[start] = 0;
    heap->nodes[start].dist = 0;
    heap->pos[start] = 0;
    heap->size = n;

    while (heap->size > 0) {
        MinHeapNode minNode = extractMin(heap);
        int u = minNode.vertex;

        Edge *edge = graph[u].head;
        while (edge != NULL) {
            int v = edge->to;

            if (isInMinHeap(heap, v) && dist[u] != INF &&
                dist[u] + edge->weight < dist[v]) {
                dist[v] = dist[u] + edge->weight;
                decreaseKey(heap, v, dist[v]);
            }
            edge = edge->next;
        }
    }

    printf("節點 %d 到其他節點的最短距離：\n", start);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("到節點 %d：無法到達\n", i);
        else
            printf("到節點 %d：%d\n", i, dist[i]);
    }

    free(heap->nodes);
    free(heap->pos);
    free(heap);
}

int main() {
    int n, m;
    Graph graph;
    printf("輸入節點數和邊數：");
    scanf("%d %d", &n, &m);

    initGraph(graph, n);
    printf("輸入每條邊（格式：起點 終點 權重）：\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    int start;
    printf("輸入起點：");
    scanf("%d", &start);

    dijkstra(graph, start, n);

    return 0;
}

// #解法二
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define INF INT_MAX
#define MAXV 1000

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
        visited[i] = false;
    }
    dist[start] = 0;
    for(int i = 0; i < n - 1; ++i) {
        int u = findMinDistance(n);
        if(u == -1)
            break;
        visited[u] = true;
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
    putchar('\n');
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
        graph[v][edgeCount[v]++].weight = w;
        */
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
