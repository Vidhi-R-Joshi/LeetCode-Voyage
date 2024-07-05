# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        cpoints = []
        prev = head
        curr = head.next
        idx = 1

        while curr and curr.next:
            if (prev.val < curr.val > curr.next.val) or (prev.val > curr.val < curr.next.val):
                cpoints.append(idx)
            prev = curr
            curr = curr.next
            idx += 1
        
        if len(cpoints) < 2:
            return [-1, -1]
        
        min_dist = float('inf')

        for i in range(1, len(cpoints)):
            dist = cpoints[i] - cpoints[i - 1]
            min_dist = min(min_dist, dist)
        
        max_dist = cpoints[-1] - cpoints[0]
        
        return [min_dist, max_dist]
