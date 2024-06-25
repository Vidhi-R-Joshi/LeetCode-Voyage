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
    public TreeNode bstToGst(TreeNode root) {
        traverse(root, 0);
        return root;
    }

    private int traverse(TreeNode node, int sum) {
        if (node == null) {
            return sum;
        }

        sum = traverse(node.right, sum);
        
        node.val += sum;
        sum = node.val;
        
        return traverse(node.left, sum);
    }
}