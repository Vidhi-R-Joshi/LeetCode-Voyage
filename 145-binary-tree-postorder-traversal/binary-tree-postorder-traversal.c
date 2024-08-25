/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode* node, int** res, int* returnSize) {
    if (node == NULL) {
        return;
    }
    traverse(node->left, res, returnSize);
    traverse(node->right, res, returnSize);
    (*res)[(*returnSize)++] = node->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    traverse(root, &res, returnSize);
    return res;
}