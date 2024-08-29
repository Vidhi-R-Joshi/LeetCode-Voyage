class Solution(object):
    def removeStones(self, stones):
        n = len(stones)
        graph = [[] for _ in range(n)]

        for i in range(n):
            for j in range(i + 1, n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    graph[i].append(j)
                    graph[j].append(i)

        def dfs(node, visited):
            visited.add(node)
            for neighbor in graph[node]:
                if neighbor not in visited:
                    dfs(neighbor, visited)

        max_removed = 0
        visited = set()
        for i in range(n):
            if i not in visited:
                dfs(i, visited)
                max_removed += 1

        return n - max_removed
