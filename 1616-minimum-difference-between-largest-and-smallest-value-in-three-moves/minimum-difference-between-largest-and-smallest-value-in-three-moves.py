class Solution:
    def minDifference(self, nums):
        n = len(nums)
        if n <= 4:
            return 0

        nums.sort()

        x = float('inf')
        for i in range(4):
            x = min(x, nums[-4 + i] - nums[i])

        return x
