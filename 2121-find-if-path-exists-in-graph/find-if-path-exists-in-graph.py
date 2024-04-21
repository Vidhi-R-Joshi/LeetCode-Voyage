class Solution(object):
    def validPath(self, n, edges, source, destination):
        g = {i: [] for i in range(n)}
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        visited = set()
        q = deque([source])

        while q:
            curr = q.popleft()
            if curr == destination:
                return True
            visited.add(curr)
            for i in g[curr]:
                if i not in visited:
                    visited.add(i)
                    q.append(i)
        
        return False