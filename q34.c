#include <stdio.h>
#include <ctype.h>
#include <string.h>
int calculate(char s[]) {
    int stack[1000];
    int top = -1;   
    int num = 0;
    char sign = '+';
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        if(isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
            if(sign == '+') {
                stack[++top] = num;
            }
            else if(sign == '-') {
                stack[++top] = -num;
            }
            else if(sign == '*') {
                stack[top] = stack[top] * num;
            }
            else if(sign == '/') {
                stack[top] = stack[top] / num;   // truncates toward zero
            }
            sign = s[i];
            num = 0;
        }
    }
    int result = 0;
    for(int i = 0; i <= top; i++) {
        result += stack[i];
    }
    return result;
}
int main() {
    char s[1000];
    printf("Enter expression: ");
    fgets(s, sizeof(s), stdin);
    printf("Result = %d\n", calculate(s));
    return 0;
}
