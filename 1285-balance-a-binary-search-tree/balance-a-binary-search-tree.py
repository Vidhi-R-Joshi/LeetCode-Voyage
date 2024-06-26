# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def balanceBST(self, root):
        def inorder(node):
            if not node:
                return []
            return inorder(node.left) + [node.val] + inorder(node.right)
        
        def array_to_tree(l, r):
            if l > r:
                return None
            mid = (l + r) // 2
            node = TreeNode(inorder[mid])
            node.left = array_to_tree(l, mid - 1)
            node.right = array_to_tree(mid + 1, r)
            return node
        
        inorder = inorder(root)
        return array_to_tree(0, len(inorder) - 1)
