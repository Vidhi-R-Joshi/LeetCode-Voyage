# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSubPath(self, head, root):
        """
        :type head: ListNode
        :type root: TreeNode
        :rtype: bool
        """
        def isConSubPath(head, root):
            if not head:
                return True
            if not root:
                return False
            return head.val == root.val and (isConSubPath(head.next, root.left) or (isConSubPath(head.next, root.right)))

        if not root:
            return False
        return isConSubPath(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)