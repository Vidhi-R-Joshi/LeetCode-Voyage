class Solution(object):
    def maximalRectangle(self, matrix):
        if not matrix[0]:
            return 0
        
        x, y = len(matrix), len(matrix[0])
        l = [0] * y
        r = [y] * y
        h = [0] * y
        max_area = 0

        for i in range(x):
            lcurr, rcurr = 0, y

            for j in range(y):
                if matrix[i][j] == '1':
                    h[j] += 1
                else:
                    h[j] = 0
    
            for j in range(y):
                if matrix[i][j] == '1':
                    l[j] = max(l[j], lcurr)
                else:
                    l[j] = 0
                    lcurr = j + 1
    
            for j in range(y - 1, -1, -1):
                if matrix[i][j] == '1':
                    r[j] = min(r[j], rcurr)
                else:
                    r[j] = y
                    rcurr = j
    
            for j in range(y):
                max_area = max(max_area, (r[j] - l[j]) * h[j])

        return max_area