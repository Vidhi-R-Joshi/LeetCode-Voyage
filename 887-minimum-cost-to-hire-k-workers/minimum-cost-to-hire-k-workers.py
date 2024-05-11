class Solution(object):
    def mincostToHireWorkers(self, quality, wage, k):
        n = len(quality)
        x = sorted((((wage[i]+.0) /quality[i], quality[i]) for i in range(n)))
        h = []
        q = 0
        for i in range(k):
            heapq.heappush(h, -x[i][1])
            q += x[i][1]
        res = q * x[k-1][0]
        for i in range(k, n):
            q += x[i][1] + heapq.heapreplace(h, -x[i][1])
            res = min(res, x[i][0] * q)
        return res
