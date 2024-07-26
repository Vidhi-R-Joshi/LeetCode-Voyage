class Solution(object):
    def findTheCity(self, n, edges, distanceThreshold):
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))
        
        def dijkstra(city):
            distances = [float('inf')] * n
            distances[city] = 0
            pq = [(0, city)]

            while pq:
                curr_dist, curr_city = heapq.heappop(pq)
                for neighbor, weight in graph[curr_city]:
                    if curr_dist + weight < distances[neighbor]:
                        distances[neighbor] = curr_dist + weight
                        heapq.heappush(pq, (distances[neighbor], neighbor))

            count = sum(1 for dist in distances if dist <= distanceThreshold)
            return count

        min_count = float('inf')
        result = -1
        for city in range(n):
            count = dijkstra(city)
            if count <= min_count:
                min_count = count
                result = city

        return result
        