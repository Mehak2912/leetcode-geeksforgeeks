#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int sumOfLeftLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    int sum = 0;
    if (root->left != NULL &&
        root->left->left == NULL &&
        root->left->right == NULL) {
        sum += root->left->data;
    }
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    printf("Sum of left leaves: %d\n", sumOfLeftLeaves(root));
    return 0;
}
