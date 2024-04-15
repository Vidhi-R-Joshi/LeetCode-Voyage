# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        self.res = 0

        def dfs(root, curr_sum):
            if not root: return
            curr_sum = curr_sum * 10 + root.val

            if not root.left and not root.right:
                self.res += curr_sum
                return
            
            dfs(root.left, curr_sum)
            dfs(root.right, curr_sum)

        dfs(root, 0)

        return self.res