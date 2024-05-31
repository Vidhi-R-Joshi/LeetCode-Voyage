class Solution(object):
    def singleNumber(self, nums):
        res = []

        for i in range(len(nums)):
            if nums.count(nums[i]) == 1:
                res.append(nums[i])
            else:
                i += 1
        
        return res
