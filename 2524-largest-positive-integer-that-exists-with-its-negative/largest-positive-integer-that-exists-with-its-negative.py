class Solution(object):
    def findMaxK(self, nums):
        n = set(nums)
        x = -1

        for i in nums:
            if -i in n:
                x = max(x, abs(i))
        
        return x if x != -1 else -1