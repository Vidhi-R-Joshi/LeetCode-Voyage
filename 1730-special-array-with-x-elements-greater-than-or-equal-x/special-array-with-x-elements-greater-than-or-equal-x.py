class Solution(object):
    def specialArray(self, nums):
        n = len(nums)
        prev = -1
        nums.sort()

        for i in range(n):
            if(n - i <= nums[i] and n - i > prev):
                return n - i
            prev = nums[i]
        
        return -1
