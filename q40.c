#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int n) {
    int* ans = (int*)calloc(n, sizeof(int));
    int stack[n];
    int top = -1;

    for(int i = 0; i < n; i++) {
        while(top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }
        stack[++top] = i;
    }

    return ans;
}

int main() {
    int temps[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(temps)/sizeof(temps[0]);

    int* result = dailyTemperatures(temps, n);

    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}
