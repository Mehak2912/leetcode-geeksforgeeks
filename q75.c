#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int queue[MAX];
bool isBipartite(int graph[MAX][MAX], int size[], int n) {
    int color[MAX];
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
    for (int start = 0; start < n; start++) {
        if (color[start] != -1) continue;
        int front = 0, rear = 0;
        queue[rear++] = start;
        color[start] = 0;
        while (front < rear) {
            int node = queue[front++];
            for (int i = 0; i < size[node]; i++) {
                int neighbor = graph[node][i];
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    int n = 4;
    int graph[MAX][MAX] = {
        {1, 2, 3},  
        {0, 2},     
        {0, 1, 3},  
        {0, 2}      
    };
    int size[] = {3, 2, 3, 2}; // number of neighbors
    if (isBipartite(graph, size, n))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
