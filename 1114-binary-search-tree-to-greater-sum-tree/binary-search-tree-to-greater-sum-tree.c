/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int traverse(struct TreeNode *node, int sum) {
    if (node == NULL) {
        return sum;
    }

    sum = traverse(node->right, sum);

    node->val += sum;
    sum = node->val;

    return traverse(node->left, sum);
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    traverse(root, 0);
    return root;
}