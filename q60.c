#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int cameras = 0;
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; // Null nodes are considered covered
    int left = dfs(root->left);
    int right = dfs(root->right);
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // Place camera here
    }
    if (left == 1 || right == 1) {
        return 2; // Covered
    }
    return 0; // Not covered
}
int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == 0)
        cameras++;
    return cameras;
}
