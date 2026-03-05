#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    if (top == -1)
        return '#';
    return stack[top--];
}
int isValid(char s[]) {
    for (int i = 0; i < strlen(s); i++) {       
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1)
                return 0;
            char temp = pop();
            if ((s[i] == ')' && temp != '(') ||
                (s[i] == '}' && temp != '{') ||
                (s[i] == ']' && temp != '[')) {
                return 0;
            }
        }
    }
    if (top == -1)
        return 1;
    else
        return 0;
}
int main() {
    char s[100];   
    scanf("%s", s);
    if (isValid(s))
        printf("Valid");
    else
        printf("Invalid");
    return 0;
}
