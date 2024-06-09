class Solution(object):
    def subarraysDivByK(self, nums, k):
        dp = defaultdict(int)
        dp[0] = 1

        res = 0
        x = 0

        for i in nums:
            x += i
            y = ((x % k) + k) % k
            res += dp[y]
            dp[y] += 1
        
        return res
