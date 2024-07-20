class Solution(object):
    def restoreMatrix(self, rowSum, colSum):
        x, y = len(rowSum), len(colSum)
        res = [[0] * y for _ in range(x)]

        for i in range(x):
            for j in range(y):
                val = min(rowSum[i], colSum[j])
                res[i][j] = val
                rowSum[i] -= val
                colSum[j] -= val
        
        return res
