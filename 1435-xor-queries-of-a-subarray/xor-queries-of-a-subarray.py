class Solution:
    def xorQueries(self, arr, queries):
        n = len(arr)

        for i in range(1, n):
            arr[i] ^= arr[i - 1]

        m = len(queries)
        res = [0] * m

        for i in range(m):
            res[i] = arr[queries[i][1]] ^ (arr[queries[i][0] - 1] if queries[i][0] > 0 else 0)
        
        return res
