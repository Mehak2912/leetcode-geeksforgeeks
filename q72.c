#include <stdio.h>
#include <limits.h>
#define MAXN 15
#define INF INT_MAX
int n;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN];
int min(int a, int b) {
    return a < b ? a : b;
}
int tsp() {
    int totalMask = 1 << n;
    for (int i = 0; i < totalMask; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0; // Start from city 0
    for (int mask = 1; mask < totalMask; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int newMask = mask | (1 << v);
                if (dp[mask][u] != INF) {
                    dp[newMask][v] = min(dp[newMask][v],
                        dp[mask][u] + cost[u][v]);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (dp[totalMask - 1][i] != INF) {
            ans = min(ans,
                dp[totalMask - 1][i] + cost[i][0]);
        }
    }
    return ans;
}
int main() {
    n = 3;
    int input[3][3] = {
        {0, 1000, 5000},
        {5000, 0, 1000},
        {1000, 5000, 0}
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = input[i][j];
    printf("%d\n", tsp()); // Output: 3000
    return 0;
}
