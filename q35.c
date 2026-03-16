#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push(int x)
{
    s1[++top1] = x;
}

int pop()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    if(top2 == -1)
        return -1;

    return s2[top2--];
}

int peek()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    if(top2 == -1)
        return -1;

    return s2[top2];
}

bool empty()
{
    return (top1 == -1 && top2 == -1);
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("%d\n", peek()); // 10
    printf("%d\n", pop());  // 10
    printf("%d\n", pop());  // 20
    printf("%d\n", empty()); // 0 (false)

    return 0;
}
