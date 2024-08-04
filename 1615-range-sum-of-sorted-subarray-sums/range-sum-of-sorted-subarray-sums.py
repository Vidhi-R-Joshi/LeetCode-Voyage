class Solution:
    def rangeSum(self, nums, n, left, right):
        return sum(sorted([sum(nums[start:end]) for start in range(len(nums)) for end in range(start + 1, len(nums)+1)])[left-1:right]) % (10**9 +7)