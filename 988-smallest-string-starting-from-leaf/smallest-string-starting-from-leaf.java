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
// Definition for a binary tree node.
class Solution {
    public String smallestFromLeaf(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        traverse(root, path, res);
        
        List<String> strings = new ArrayList<>();
        for (List<Integer> list : res) {
            Collections.reverse(list);
            StringBuilder sb = new StringBuilder();
            for (int val : list) {
                sb.append((char)(val + 'a'));
            }
            strings.add(sb.toString());
        }
        
        Collections.sort(strings);
        return strings.get(0);
    }
    
    private void traverse(TreeNode node, List<Integer> path, List<List<Integer>> res) {
        if (node == null) {
            return;
        }
        
        path.add(node.val);
        if (node.left == null && node.right == null) {
            res.add(new ArrayList<>(path));
        } else {
            traverse(node.left, path, res);
            traverse(node.right, path, res);
        }
        path.remove(path.size() - 1);
    }
}

