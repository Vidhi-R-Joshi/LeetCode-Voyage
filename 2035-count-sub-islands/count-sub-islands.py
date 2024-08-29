class Solution:
    def countSubIslands(self, grid1, grid2):
        rows = len(grid1)
        cols = len(grid1[0])
        sub_island_count = 0

        for i in range(rows):
            for j in range(cols):
                if grid2[i][j] == 1:
                    if self.dfs(grid1, grid2, i, j):
                        sub_island_count += 1

        return sub_island_count

    def dfs(self, grid1, grid2, i, j):
        if i < 0 or j < 0 or i >= len(grid1) or j >= len(grid1[0]) or grid2[i][j] == 0:
            return True

        grid2[i][j] = 0
        is_sub_island = grid1[i][j] == 1

        up = self.dfs(grid1, grid2, i - 1, j)
        down = self.dfs(grid1, grid2, i + 1, j)
        left = self.dfs(grid1, grid2, i, j - 1)
        right = self.dfs(grid1, grid2, i, j + 1)

        return is_sub_island and up and down and left and right