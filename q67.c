#include <stdio.h>
#include <stdlib.h>
#define MAX 2000
int adj[MAX][MAX];
int visited[MAX], path[MAX];
int stack[MAX], top = -1;
int hasCycle = 0;
void push(int node) {
    stack[++top] = node;
}
void dfs(int node, int n) {
    if (hasCycle) return;
    visited[node] = 1;
    path[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                dfs(i, n);
            } else if (path[i]) {
                hasCycle = 1;  // cycle detected
                return;
            }
        }
    }
    path[node] = 0;
    push(node);
}
int* findOrder(int numCourses, int prerequisites[][2], int prereqSize, int* returnSize) {
    for (int i = 0; i < numCourses; i++) {
        visited[i] = path[i] = 0;
        for (int j = 0; j < numCourses; j++) {
            adj[i][j] = 0;
        }
    }
    top = -1;
    hasCycle = 0;
    for (int i = 0; i < prereqSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][a] = 1;  // b -> a
    }
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            dfs(i, numCourses);
        }
    }
    if (hasCycle) {
        *returnSize = 0;
        return NULL;
    }
    int* result = (int*)malloc(numCourses * sizeof(int));
    *returnSize = numCourses;
    int index = 0;
    while (top != -1) {
        result[index++] = stack[top--];
    }
    return result;
}
