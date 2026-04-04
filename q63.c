#include <stdio.h>
#define MAX 50
void dfs(int image[MAX][MAX], int m, int n, int r, int c, int oldColor, int newColor) {
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;
    if (image[r][c] != oldColor)
        return;
    image[r][c] = newColor;
    dfs(image, m, n, r+1, c, oldColor, newColor); // down
    dfs(image, m, n, r-1, c, oldColor, newColor); // up
    dfs(image, m, n, r, c+1, oldColor, newColor); // right
    dfs(image, m, n, r, c-1, oldColor, newColor); // left
}
int main() {
    int m, n;
    int image[MAX][MAX];
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter image matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    int sr, sc, color;
    printf("Enter starting row, column and new color: ");
    scanf("%d %d %d", &sr, &sc, &color);
    int oldColor = image[sr][sc];
    if (oldColor != color) {
        dfs(image, m, n, sr, sc, oldColor, color);
    }
    printf("Updated Image:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}
