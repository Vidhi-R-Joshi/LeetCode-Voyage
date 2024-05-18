/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int distributeCoins(struct TreeNode* root) {
    int res = 0;

    int dfs(struct TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        int l = dfs(node->left);
        int r = dfs(node->right);
        res += abs(l) + abs(r);
        return node->val + l + r - 1;
    }
    
    dfs(root);
    return res;
}

