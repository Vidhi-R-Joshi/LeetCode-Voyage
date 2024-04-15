/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumNumbers(struct TreeNode* root) {
    int res = 0;

    void dfs(struct TreeNode* root, int curr_sum) {
        if (!root) return;
        curr_sum = curr_sum * 10 + root->val;

        if (!root->left && !root->right) {
            res += curr_sum;
            return;
        }
        
        dfs(root->left, curr_sum);
        dfs(root->right, curr_sum);
    }

    dfs(root, 0);

    return res;
}

