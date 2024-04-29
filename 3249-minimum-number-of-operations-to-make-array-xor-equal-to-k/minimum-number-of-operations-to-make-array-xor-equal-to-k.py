class Solution(object):
    def minOperations(self, nums, k):
        tmp = 0

        for i in nums:
            tmp ^= i
            
        tmp ^= k

        return bin(tmp).count('1')