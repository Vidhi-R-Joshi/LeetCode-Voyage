class Solution(object):
    def regionsBySlashes(self, grid):
        n = len(grid)
        graph = [[0] * (n * 3) for _ in range(n * 3)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    graph[i * 3][j * 3 + 2] = graph[i * 3 + 1][j * 3 + 1] = graph[i * 3 + 2][j * 3] = 1
                if grid[i][j] == '\\':
                    graph[i * 3][j * 3] = graph[i * 3 + 1][j * 3 + 1] = graph[i * 3 + 2][j * 3 + 2] = 1

        def dfs(i, j):
            if 0 <= i < n * 3 and 0 <= j < n * 3 and graph[i][j] == 0:
                graph[i][j] = 1
                dfs(i - 1, j)
                dfs(i + 1, j)
                dfs(i, j - 1)
                dfs(i, j + 1)

        res = 0
        for i in range(n * 3):
            for j in range(n * 3):
                if graph[i][j] == 0:
                    dfs(i, j)
                    res += 1
        return res
