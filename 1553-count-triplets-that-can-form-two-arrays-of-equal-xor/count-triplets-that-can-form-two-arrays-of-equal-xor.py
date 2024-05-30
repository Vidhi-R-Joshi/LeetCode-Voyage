class Solution(object):
    def countTriplets(self, arr):
        x = collections.defaultdict(list)
        y = 0
        x[0] = [-1]
        res = 0

        for i, j in enumerate(arr):
            y ^= j

            for k in x[y]:
                res += (i - k - 1)
            x[y].append(i)
        
        return res
