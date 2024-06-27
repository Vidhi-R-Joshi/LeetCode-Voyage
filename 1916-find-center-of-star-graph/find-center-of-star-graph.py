class Solution(object):
    def findCenter(self, edges):
        n = len(edges) + 1
        graph = [[] for _ in range(n + 1)]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        for i in range(1, n + 1):
            if len(graph[i]) == n - 1:
                return i
