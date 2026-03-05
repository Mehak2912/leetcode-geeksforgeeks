#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    char tokens[MAX][10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", tokens[i]);
    }

    for (int i = 0; i < n; i++) {

        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            int b = pop();
            int a = pop();
            int result;

            if (strcmp(tokens[i], "+") == 0)
                result = a + b;
            else if (strcmp(tokens[i], "-") == 0)
                result = a - b;
            else if (strcmp(tokens[i], "*") == 0)
                result = a * b;
            else
                result = a / b;

            push(result);
        }
        else {
            push(atoi(tokens[i]));
        }
    }

    printf("%d", pop());

    return 0;
}
