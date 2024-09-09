# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def splitListToParts(self, head, k):
        result = [None] * k
        
        len_ = 0
        current = head
        while current is not None:
            len_ += 1
            current = current.next
        
        size = len_ // k
        extra = len_ % k
        
        current = head
        for i in range(k):
            if current is None:
                result[i] = None
            else:
                result[i] = current
                part_size = size + (1 if extra > 0 else 0)
                extra -= 1
                
                for j in range(1, part_size):
                    if current is not None:
                        current = current.next
                
                if current is not None:
                    next_part = current.next
                    current.next = None
                    current = next_part
        
        return result
    