class Solution(object):
    def minFallingPathSum(self, grid):
        n = len(grid)

        for i in range(1, n):
            (x, y), (z, _) = sorted({(k, i) for i, k in enumerate(grid[i - 1])})[:2]
            for j in range(n):
                if j == y:
                    grid[i][j] += z
                else:
                    grid[i][j] += x
        
        return min(grid[-1])
