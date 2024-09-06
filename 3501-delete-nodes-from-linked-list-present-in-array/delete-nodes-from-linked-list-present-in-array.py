# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def modifiedList(self, nums, head):
        nums = set(nums) 
        ans = ListNode(0)
        tail = ans

        while head:
            val = head.val
            head = head.next
            if val not in nums:
                tail.next = ListNode(val)
                tail = tail.next
        return ans.next
