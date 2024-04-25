class Solution:
    def longestIdealString(self, s, k):
        n = len(s)
        dp = [[-1] * 27 for _ in range(n)]

        def rec(i, last):
            if i == n:
                return 0
            if dp[i][last] != -1:
                return dp[i][last]
            ans = 0
            if last == 26 or abs(ord(s[i]) - ord('a') - last) <= k:
                ans = rec(i + 1, ord(s[i]) - ord('a')) + 1
            ans = max(ans, rec(i + 1, last))
            dp[i][last] = ans
            return ans

        return rec(0, 26)

