#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 105
#define INF INT_MAX
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;
typedef struct {
    int node, dist;
} HeapNode;
HeapNode heap[10000];
int size = 0;
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].dist > heap[i].dist) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}
void heapifyDown(int i) {
    int l, r, smallest;
    while (1) {
        l = 2 * i + 1;
        r = 2 * i + 2;
        smallest = i;
        if (l < size && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if (r < size && heap[r].dist < heap[smallest].dist)
            smallest = r;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}
int isEmpty() {
    return size == 0;
}
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}
int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    Node* adj[MAX] = {NULL};
    for (int i = 0; i < timesSize; i++) {
        addEdge(adj, times[i][0], times[i][1], times[i][2]);
    }
    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[k] = 0;
    push(k, 0);
    while (!isEmpty()) {
        HeapNode top = pop();
        int u = top.node;
        int d = top.dist;
        if (d > dist[u]) continue;
        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }
    return maxTime;
}
int main() {
    int times[][3] = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    int result = networkDelayTime(times, 3, n, k);
    printf("Output: %d\n", result);
    return 0;
}
