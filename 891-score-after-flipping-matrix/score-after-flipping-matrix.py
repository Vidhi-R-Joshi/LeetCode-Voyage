class Solution(object):
    def matrixScore(self, grid):
        m, n = len(grid), len(grid[0])
        res = m

        for j in range(1, n):
            cnt1 = 0
            for i in range(m):
                cnt1 += 1 if grid[i][j] == grid[i][0] else 0
            res = res * 2 + max(cnt1, m - cnt1)
        
        return res