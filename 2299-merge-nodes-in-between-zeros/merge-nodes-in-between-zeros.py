# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeNodes(self, head):
        x = ListNode(0)
        curr = x
        tmp = 0

        while head:
            if head.val == 0:
                if tmp != 0:
                    curr.next = ListNode(tmp)
                    curr = curr.next
                    tmp = 0
            else:
                tmp += head.val
            head = head.next
        
        return x.next
