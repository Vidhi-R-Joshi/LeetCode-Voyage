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
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> nodes = new HashMap<>();
        Set<Integer> children = new HashSet<>();

        for (int[] description : descriptions) {
            int parent = description[0];
            int child = description[1];
            boolean isLeft = description[2] == 1;

            nodes.putIfAbsent(parent, new TreeNode(parent));
            nodes.putIfAbsent(child, new TreeNode(child));

            if (isLeft) {
                nodes.get(parent).left = nodes.get(child);
            } else {
                nodes.get(parent).right = nodes.get(child);
            }
            children.add(child);
        }

        for (int[] description : descriptions) {
            int parent = description[0];
            if (!children.contains(parent)) {
                return nodes.get(parent);
            }
        }

        return null;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] descriptions = {
            {1, 2, 1},
            {1, 3, 0},
            {2, 4, 1}
        };

        TreeNode root = solution.createBinaryTree(descriptions);
    }
}