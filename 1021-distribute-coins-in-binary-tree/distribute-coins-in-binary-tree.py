# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def distributeCoins(self, root):
        self.res = 0

        def dfs(node):
            if not node:
                return 0
            
            l, r = dfs(node.left), dfs(node.right)
            self.res += abs(l) + abs(r)
            return node.val + l + r - 1
        
        dfs(root)

        return self.res
