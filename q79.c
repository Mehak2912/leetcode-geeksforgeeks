#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
int head[MAX], to[MAX], next[MAX], edge_count;
int rhead[MAX], rto[MAX], rnext[MAX], redge_count;
int stack[MAX], top = -1;
int visited[MAX];
void addEdge(int u, int v) {
    to[edge_count] = v;
    next[edge_count] = head[u];
    head[u] = edge_count++;
}
void addReverseEdge(int u, int v) {
    rto[redge_count] = v;
    rnext[redge_count] = rhead[u];
    rhead[u] = redge_count++;
}
void dfs1(int u) {
    visited[u] = 1;
    for (int i = head[u]; i != -1; i = next[i]) {
        int v = to[i];
        if (!visited[v]) {
            dfs1(v);
        }
    }
    stack[++top] = u;
}
void dfs2(int u) {
    visited[u] = 1;
    for (int i = rhead[u]; i != -1; i = rnext[i]) {
        int v = rto[i];
        if (!visited[v]) {
            dfs2(v);
        }
    }
}
int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        head[i] = -1;
        rhead[i] = -1;
        visited[i] = 0;
    }
    edge_count = 0;
    redge_count = 0;
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addReverseEdge(v, u); // reverse
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    int scc_count = 0;
    while (top != -1) {
        int u = stack[top--];
        if (!visited[u]) {
            dfs2(u);
            scc_count++;
        }
    }
    printf("%d\n", scc_count);
    return 0;
}
