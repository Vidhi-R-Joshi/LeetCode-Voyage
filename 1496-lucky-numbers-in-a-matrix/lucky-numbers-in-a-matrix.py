class Solution(object):
    def luckyNumbers (self, matrix):
        m, n = len(matrix), len(matrix[0])
        rowMin = [min(row) for row in matrix]
        colMax = [max([matrix[i][j] for i in range(m)]) for j in range(n)]
        return [num for num in rowMin if num in colMax]