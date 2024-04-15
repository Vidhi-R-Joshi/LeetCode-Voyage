/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int res = 0;

    public int sumNumbers(TreeNode root) {
        dfs(root, 0);
        return res;
    }

    private void dfs(TreeNode root, int currSum) {
        if (root == null) return;
        currSum = currSum * 10 + root.val;

        if (root.left == null && root.right == null) {
            res += currSum;
            return;
        }

        dfs(root.left, currSum);
        dfs(root.right, currSum);
    }
}

