class Solution:
    def minPatches(self, nums, n):
        patch = 1
        total = 0
        index = 0

        while patch <= n:
            if index < len(nums) and patch >= nums[index]:
                patch += nums[index]
                index += 1
            else:
                patch += patch
                total += 1

        return total
