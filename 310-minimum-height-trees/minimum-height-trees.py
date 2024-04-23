class Solution(object):
    def findMinHeightTrees(self, n, edges):
        if n == 1 or not edges:
            return [0]
        
        res = []
        x = defaultdict(set)

        for u, v in edges:
            x[u].add(v)
            x[v].add(u)
        
        for i, j in x.items():
            if len(j) == 1:
                res.append(i)
        
        while n > 2:
            n -= len(res)
            y = []
            for k in res:
                u = next(iter(x[k]))
                x[u].remove(k)
                if len(x[u]) == 1:
                    y.append(u)
            res = y
        
        return res
        