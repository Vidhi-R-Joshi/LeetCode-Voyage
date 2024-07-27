class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        matrix = [[float('inf')] * 26 for _ in range(26)]

        for i in range(26):
            matrix[i][i] = 0
        
        for i in range(len(cost)):
            s = ord(original[i]) - ord('a')
            d = ord(changed[i]) - ord('a')
            matrix[s][d] = min(cost[i], matrix[s][d])
        
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if matrix[i][j] > matrix[i][k] + matrix[k][j]:
                        matrix[i][j] = matrix[i][k] + matrix[k][j]
        
        ans = 0
        for i in range(len(source)):
            s = ord(source[i]) - ord('a')
            d = ord(target[i]) - ord('a')
            if matrix[s][d] != float('inf'):
                ans += matrix[s][d]
            else:
                return -1
        
        return ans