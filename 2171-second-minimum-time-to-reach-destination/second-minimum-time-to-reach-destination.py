class Solution(object):
    def secondMinimum(self, n, edges, time, change):
        graph = [[] for _ in range(n + 1)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        pq = [(0, 1)]
        dist = [[float('inf')] * 2 for _ in range(n + 1)]
        dist[1][0] = 0

        while pq:
            d, node = heapq.heappop(pq)
            if node == n and dist[node][1] != float('inf'):
                return dist[node][1]

            if d % (2 * change) >= change:
                d = (d // (2 * change) + 1) * 2 * change

            for neighbor in graph[node]:
                new_d = d + time
                if new_d < dist[neighbor][0]:
                    dist[neighbor][1] = dist[neighbor][0]
                    dist[neighbor][0] = new_d
                    heapq.heappush(pq, (new_d, neighbor))
                elif new_d > dist[neighbor][0] and new_d < dist[neighbor][1]:
                    dist[neighbor][1] = new_d
                    heapq.heappush(pq, (new_d, neighbor))

        return -1
