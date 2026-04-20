#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
int head[MAX], to[2 * MAX], next[2 * MAX];
int edge_count = 0;
int disc[MAX], low[MAX], visited[MAX];
int time_counter = 0;
int isAP[MAX];
void addEdge(int u, int v) {
    to[edge_count] = v;
    next[edge_count] = head[u];
    head[u] = edge_count++;
}
void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++time_counter;
    int children = 0;
    for (int i = head[u]; i != -1; i = next[i]) {
        int v = to[i];
        if (v == parent)
            continue;
        if (!visited[v]) {
            children++;
            dfs(v, u);
            if (low[v] < low[u])
                low[u] = low[v];
            if (parent != -1 && low[v] >= disc[u]) {
                isAP[u] = 1;
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
    if (parent == -1 && children > 1) {
        isAP[u] = 1;
    }
}
int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        head[i] = -1;
        visited[i] = 0;
        disc[i] = 0;
        low[i] = 0;
        isAP[i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(0, -1);
    int found = 0;
    for (int i = 0; i < V; i++) {
        if (isAP[i]) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("-1");
    }
    return 0;
}
