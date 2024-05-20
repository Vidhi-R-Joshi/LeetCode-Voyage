class Solution(object):
    def subsetXORSum(self, nums):
        res, x = 0, len(nums)

        for i in range(1 << x):
            y = 0

            for j in range(x):
                if i >> j & 1:
                    y ^= nums[j]
            
            res += y
        
        return res
