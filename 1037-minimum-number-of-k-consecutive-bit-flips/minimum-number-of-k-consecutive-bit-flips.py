class Solution(object):
    def minKBitFlips(self, nums, k):
        n = len(nums)
        x = 0
        y = 0
        z = [0] * n

        for i in range(n):
            if i >= k:
                y ^= z[i - k]
            
            if nums[i] == y:
                if i + k > n:
                    return -1
                x += 1
                y ^= 1
                if i < n:
                    z[i] = 1
        
        return x
