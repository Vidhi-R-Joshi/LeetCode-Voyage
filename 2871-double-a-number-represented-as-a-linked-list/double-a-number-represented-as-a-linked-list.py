# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def doubleIt(self, head):
        if head.val > 4:
            head = ListNode(0, head)
        
        tmp = head
        while tmp is not None:
            tmp.val = (tmp.val * 2) % 10
            if tmp.next is not None and tmp.next.val > 4:
                tmp.val += 1
            
            tmp = tmp.next
        
        return head