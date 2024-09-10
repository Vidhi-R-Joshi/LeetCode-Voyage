class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def gcd(self, a, b):
        while b:
            a, b = b, a % b
        return a

    def insertGreatestCommonDivisors(self, head):
        if not head or not head.next:
            return head
        
        curr = head
        while curr.next:
            x = self.gcd(curr.val, curr.next.val)
            y = ListNode(x)
            y.next = curr.next
            curr.next = y
            curr = y.next
        
        return head
