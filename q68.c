#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 26
int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}
int dequeue() {
    if (front == -1) return -1;
    int x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}
int isEmpty() {
    return front == -1;
}
char* alienOrder(char words[][100], int n) {
    static char result[27];
    int adj[MAX][MAX] = {0};
    int in_degree[MAX] = {0};
    int present[MAX] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];
        int len1 = strlen(w1);
        int len2 = strlen(w2);
        int found = 0;
        for (int j = 0; j < len1 && j < len2; j++) {
            if (w1[j] != w2[j]) {
                if (!adj[w1[j]-'a'][w2[j]-'a']) {
                    adj[w1[j]-'a'][w2[j]-'a'] = 1;
                    in_degree[w2[j]-'a']++;
                }
                found = 1;
                break;
            }
        }
        if (!found && len1 > len2) {
            return "";
        }
    }
    for (int i = 0; i < MAX; i++) {
        if (present[i] && in_degree[i] == 0) {
            enqueue(i);
        }
    }
    int index = 0;
    while (!isEmpty()) {
        int node = dequeue();
        result[index++] = node + 'a';
        for (int j = 0; j < MAX; j++) {
            if (adj[node][j]) {
                in_degree[j]--;
                if (in_degree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }
    int total = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) total++;
    }
    if (index != total) {
        return "";
    }
    result[index] = '\0';
    return result;
}
int main() {
    char words[][100] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5;
    char* order = alienOrder(words, n);
    if (strlen(order) == 0)
        printf("Invalid ordering\n");
    else
        printf("Alien Order: %s\n", order);
    return 0;
}
