#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
int findCheapestPrice(int n, int flights[][3], int flightsSize, int src, int dst, int k) {
    int dist[101], temp[101];
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];
            if (dist[u] != INF && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }
        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }
    return (dist[dst] == INF) ? -1 : dist[dst];
}
