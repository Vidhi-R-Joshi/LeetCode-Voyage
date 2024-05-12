class Solution(object):
    def largestLocal(self, grid):
        n = len(grid)
        
        maxLocal = [[0] * (n - 2) for _ in range(n - 2)]
        for i in range(1, n - 1):
            for j in range(1, n - 1):
                subMatrix = [row[j - 1:j + 2] for row in grid[i - 1:i + 2]]
                maxLocal[i - 1][j - 1] = max(max(subMatrix, key=max))
        return maxLocal