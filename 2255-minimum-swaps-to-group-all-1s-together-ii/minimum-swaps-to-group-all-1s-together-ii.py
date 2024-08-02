class Solution(object):
    def minSwaps(self, nums):
        n = len(nums)
        o = sum(nums)
        if o == 0:
            return 0
        
        # Initial window sum of the first 'o' elements
        current_sum = sum(nums[:o])
        min_swaps = o - current_sum

        for i in range(1, n):
            current_sum -= nums[i - 1]
            current_sum += nums[(i + o - 1) % n]
            min_swaps = min(min_swaps, o - current_sum)
        
        return min_swaps
