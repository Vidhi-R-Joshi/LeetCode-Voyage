/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {
    if (root == NULL) {
        return root;
    }
    if (depth == 1) {
        struct TreeNode* newRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newRoot->val = val;
        newRoot->left = root;
        newRoot->right = NULL;
        return newRoot;
    }
    if (depth == 2) {
        struct TreeNode* newLeft = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newLeft->val = val;
        newLeft->left = root->left;
        newLeft->right = NULL;
        root->left = newLeft;
        
        struct TreeNode* newRight = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newRight->val = val;
        newRight->left = NULL;
        newRight->right = root->right;
        root->right = newRight;
        return root;
    }
    root->left = addOneRow(root->left, val, depth - 1);
    root->right = addOneRow(root->right, val, depth - 1);
    return root;
}

