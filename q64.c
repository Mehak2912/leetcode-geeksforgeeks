#include <stdio.h>
#define MAX 10
typedef struct {
    int x, y;
} Node;
Node queue[MAX * MAX];
int front = 0, rear = 0;
void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}
Node dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == rear;
}
int orangesRotting(int grid[MAX][MAX], int m, int n) {
    int fresh = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                enqueue(i, j);
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    if (fresh == 0) return 0;
    int minutes = 0;
    while (!isEmpty()) {
        int size = rear - front;
        int infected = 0;
        for (int i = 0; i < size; i++) {
            Node temp = dequeue();
            for (int d = 0; d < 4; d++) {
                int nx = temp.x + dx[d];
                int ny = temp.y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(nx, ny);
                    fresh--;
                    infected = 1;
                }
            }
        }
        if (infected) minutes++;
    }
    return (fresh == 0) ? minutes : -1;
}
int main() {
    int m = 3, n = 3;
    int grid[MAX][MAX] = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    printf("Output: %d\n", orangesRotting(grid, m, n));
    return 0;
}
