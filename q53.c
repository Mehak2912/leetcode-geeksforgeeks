#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct Queue {
    struct TreeNode* arr[10000];
    int front, rear;
};
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}
struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        printf("[]");
        return;
    }
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    printf("[");
    while (!isEmpty(&q)) {
        int size = q.rear - q.front;
        printf("[");
        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue(&q);
            printf("%d", curr->val);
            if (i < size - 1)
                printf(",");
            if (curr->left)
                enqueue(&q, curr->left);
            if (curr->right)
                enqueue(&q, curr->right);
        }
        printf("]");
        if (!isEmpty(&q))
            printf(",");
    }
    printf("]");
}
