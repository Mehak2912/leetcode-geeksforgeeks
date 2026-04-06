#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100005
int* adj[MAX];
int size[MAX];
bool visited[MAX];
bool dfs(int node, int parent) {
    visited[node] = true;
    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}
int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int)); // max possible
        size[i] = 0;
        visited[i] = false;
    }
    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("true\n");
                return 0;
            }
        }
    }
    printf("false\n");
    return 0;
}
