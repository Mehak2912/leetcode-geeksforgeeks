#include <stdio.h>
#define MAX 1001
int parent[MAX];
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb)
        parent[pa] = pb;
}
int* findRedundantConnection(int edges[][2], int edgesSize) {
    static int result[2];
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (find(u) == find(v)) {
            result[0] = u;
            result[1] = v;
        } else {
            unionSet(u, v);
        }
    }
    return result;
}
int main() {
    int edges[][2] = {{1,2},{1,3},{2,3}};
    int edgesSize = 3;
    int* res = findRedundantConnection(edges, edgesSize);
    printf("[%d, %d]\n", res[0], res[1]);
    return 0;
}
