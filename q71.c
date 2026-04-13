#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a, int b) {
    return a < b ? a : b;
}
int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
int minCostConnectPoints(int** points, int pointsSize) {
    int n = pointsSize;
    int minDist[1000];
    int visited[1000] = {0};
    for (int i = 0; i < n; i++)
        minDist[i] = INT_MAX;
    minDist[0] = 0;
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }
        visited[u] = 1;
        totalCost += minDist[u];
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int cost = manhattan(points[u][0], points[u][1],
                                     points[v][0], points[v][1]);
                if (cost < minDist[v]) {
                    minDist[v] = cost;
                }
            }
        }
    }
    return totalCost;
}
