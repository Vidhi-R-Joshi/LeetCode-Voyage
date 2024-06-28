class Solution(object):
    def maximumImportance(self, n, roads):
        degree = [0] * n
        for road in roads:
            degree[road[0]] += 1
            degree[road[1]] += 1
    
        sorted_cities = sorted(range(n), key=lambda x: degree[x], reverse=True)
    
        values = [0] * n
        for i in range(n):
            values[sorted_cities[i]] = n - i
    
        total_importance = 0
        for road in roads:
            total_importance += values[road[0]] + values[road[1]]
    
        return total_importance
