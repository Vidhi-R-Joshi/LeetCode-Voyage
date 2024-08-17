class Solution:
    def maxPoints(self, points):
        n = len(points)
        m = len(points[0])

        dp = [0] * m
        res = 0
        for i in range(n):
            for j in range(m):
                dp[j] += points[i][j]

            for j in range(1, m):
                dp[j] = max(dp[j], dp[j - 1] - 1)
            for j in range(m - 2, -1, -1):
                dp[j] = max(dp[j], dp[j + 1] - 1)

        for i in range(m):
            res = max(res, dp[i])
        return res
