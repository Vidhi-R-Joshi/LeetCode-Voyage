"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def PostOrder(self, root, ans):
        if root:
            for node in root.children:
                self.PostOrder(node, ans)
            ans.append(root.val)
    def postorder(self, root):
        ans = []
        self.PostOrder(root, ans)
        return ans
        