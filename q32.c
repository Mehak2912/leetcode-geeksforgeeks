#include <stdio.h>
#define MAX 100
int stack[MAX];
int minStack[MAX];
int top = -1;
int minTop = -1;
void push(int val) {
    stack[++top] = val;

    if (minTop == -1 || val <= minStack[minTop]) {
        minStack[++minTop] = val;
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    if (stack[top] == minStack[minTop]) {
        minTop--;
    }
    top--;
}
int topElement() {
    if (top == -1)
        return -1;
    return stack[top];
}
int getMin() {
    if (minTop == -1)
        return -1;
    return minStack[minTop];
}
int main() {
    push(5);
    push(3);
    push(7);
    push(2);
    printf("Top: %d\n", topElement());
    printf("Min: %d\n", getMin());
    pop();
    printf("Top after pop: %d\n", topElement());
    printf("Min after pop: %d\n", getMin());
    return 0;
}
