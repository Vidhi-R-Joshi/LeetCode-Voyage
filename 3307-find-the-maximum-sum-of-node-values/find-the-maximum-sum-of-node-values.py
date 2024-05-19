class Solution(object):
    def maximumValueSum(self, nums, k, edges):
        n = len(nums)
        diff = [0] * n
        total = sum(nums)

        for i in range(n):
            diff[i] = (nums[i] ^ k) - nums[i]
        
        diff.sort(reverse = True)

        for i in range(0, n, 2):
            if i + 1 == n:
                return total
            pair = diff[i] + diff[i + 1]
            if pair > 0:
                total += pair
        
        return total
