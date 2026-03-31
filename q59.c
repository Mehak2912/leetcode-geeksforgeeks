#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex, int map[]) {
    if (inStart > inEnd)
        return NULL;
    int rootVal = postorder[*postIndex];
    (*postIndex)--;
    struct TreeNode* root = newNode(rootVal);
    int inIndex = map[rootVal];
    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex, map);
    root->left  = build(inorder, postorder, inStart, inIndex - 1, postIndex, map);
    return root;
}
void preorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);
    int map[6001];
    for (int i = 0; i < n; i++)
        map[inorder[i] + 3000] = i;
    int postIndex = n - 1;
    struct TreeNode* root = build(inorder, postorder, 0, n - 1, &postIndex, map);
    preorder(root);
    return 0;
}
