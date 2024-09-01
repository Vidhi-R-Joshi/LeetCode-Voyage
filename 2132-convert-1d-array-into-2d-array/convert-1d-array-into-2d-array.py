class Solution:
    def construct2DArray(self, original, m, n):
        if m * n != len(original):
            return []
        grid = [[0] * n for _ in range(m)]
        ind = 0
        for i in range(m):
            for j in range(n):
                grid[i][j] = original[ind]
                ind += 1
        return grid
