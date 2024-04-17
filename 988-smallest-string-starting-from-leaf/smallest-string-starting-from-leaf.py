# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root):
        s = []
        res = []
        self.traverse(root, [], res)
        
        for i in res:
            i.reverse()
            x = []
            for j in i:
                y = chr(j + ord('a'))
                x.append(y)
            string = ''.join(x)
            
            if len(s) == 0 or string < ''.join(s):
                s = list(string)
        
        return ''.join(s)
    
    def traverse(self, root, lst, res):
        if not root:
            return
        lst.append(root.val)
        
        if not root.left and not root.right:
            res.append(list(lst))
            return
        self.traverse(root.left, list(lst), res)
        self.traverse(root.right, list(lst), res)
        
        lst.pop()     
