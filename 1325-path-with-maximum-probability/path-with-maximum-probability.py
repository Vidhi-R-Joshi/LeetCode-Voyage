class Solution(object):
    def maxProbability(self, n, edges, succProb, start_node, end_node):
        graph = {}
        for i in range(n):
            graph[i] = []
        for i, edge in enumerate(edges):
            a, b = edge
            p = succProb[i]
            graph[a].append((b, p))
            graph[b].append((a, p))

        weights = [0] * n
        weights[start_node] = 1
        pq = []
        heapq.heappush(pq, (-1, start_node))

        while pq:
            weight, node = heapq.heappop(pq)
            weight = -weight
            if node == end_node:
                return weight
            for neighbor, prob in graph[node]:
                new_weight = weight * prob
                if new_weight > weights[neighbor]:
                    weights[neighbor] = new_weight
                    heapq.heappush(pq, (-new_weight, neighbor))

        return 0.0
