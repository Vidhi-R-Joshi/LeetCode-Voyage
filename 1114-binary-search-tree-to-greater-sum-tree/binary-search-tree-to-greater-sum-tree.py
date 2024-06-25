# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def bstToGst(self, root):
        def traverse(node, sum):
            if not node:
                return sum
            
            x = traverse(node.right, sum)
            node.val += x
            y = traverse(node.left, node.val)
            return y
        
        traverse(root, 0)
        return root
