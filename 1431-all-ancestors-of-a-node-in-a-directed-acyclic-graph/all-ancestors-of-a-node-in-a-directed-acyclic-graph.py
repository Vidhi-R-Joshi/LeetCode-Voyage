class Solution(object):
    def getAncestors(self, n, edges):
        def dfs(v):
            used[v] = 0
            for u in G[v]:
                if used[u]:
                    answer[a].append(u)
                    dfs(u)
            return

        G = [[] for i in range(n)]
        for a, b in edges:
            G[b].append(a)
        answer = [[] for i in range(n)]
        for a in range(n):
            used = [1 for i in range(n)]
            dfs(a)
        return [sorted(ans) for ans in answer]