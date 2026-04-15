#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int graph[MAX][MAX];
int graphSize[MAX];   // stores number of neighbors for each node
int visited[MAX];
void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
int countComponents(int n, int edges[][2], int edgesSize) {
    for (int i = 0; i < n; i++) {
        graphSize[i] = 0;
        visited[i] = 0;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];   
        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
    return components;
}
int main() {
    int n = 5;
    int edges[][2] = {{0,1}, {1,2}, {3,4}};
    int edgesSize = 3;
    int result = countComponents(n, edges, edgesSize);
    printf("Number of Connected Components: %d\n", result);
    return 0;
}
