#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
int head[MAX], to[2 * MAX], next[2 * MAX];
int edge_count = 0;
int disc[MAX], low[MAX];
int time_counter = 0;
int bridges[MAX][2];
int bridge_count = 0;
void addEdge(int u, int v) {
    to[edge_count] = v;
    next[edge_count] = head[u];
    head[u] = edge_count++;
}
void dfs(int u, int parent) {
    disc[u] = low[u] = ++time_counter;
    for (int i = head[u]; i != -1; i = next[i]) {
        int v = to[i];
        if (v == parent)
            continue;
        if (disc[v] == 0) {
            dfs(v, u);
            if (low[v] < low[u])
                low[u] = low[v];
            if (low[v] > disc[u]) {
                bridges[bridge_count][0] = u;
                bridges[bridge_count][1] = v;
                bridge_count++;
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Initialize
    for (int i = 0; i < n; i++) {
        head[i] = -1;
        disc[i] = 0;
        low[i] = 0;
    }
    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // undirected
    }
    // Run DFS from node 0
    dfs(0, -1);
    for (int i = 0; i < bridge_count; i++) {
        printf("[%d, %d]\n", bridges[i][0], bridges[i][1]);
    }
    return 0;
}
