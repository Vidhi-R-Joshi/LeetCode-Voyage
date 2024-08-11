class Solution:
  
    def dfs(self, grid, visited, i, j):
        m, n = len(grid), len(grid[0])

        if i < 0 or j < 0 or i >= m or j >= n or grid[i][j] == 0 or visited[i][j]:
            return
        visited[i][j] = True 
        self.dfs(grid, visited, i+1, j)
        self.dfs(grid, visited, i-1, j)
        self.dfs(grid, visited, i, j+1)
        self.dfs(grid, visited, i, j-1)

    def countIslands(self, grid):
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        count = 0

        for i in range(m):
            for j in range(n):
               
                if grid[i][j] == 1 and not visited[i][j]:
                    count += 1
                    self.dfs(grid, visited, i, j) 
        return count

    def minDays(self, grid):
        if self.countIslands(grid) != 1:
            return 0
        
        m, n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0 
                 
                    if self.countIslands(grid) != 1:
                        return 1
                    grid[i][j] = 1 

        return 2