class Solution:
    def stoneGameII(self, piles):
        dp, n = {}, len(piles)
        for i in range(n - 2, -1, -1):
            piles[i] += piles[i + 1]
        
        def solve(index, m):
            if index >= n: 
                return 0
            if index + 2 * m >= n: 
                return piles[index]
            if (m, index) in dp: 
                return dp[(m, index)]
            res = 0
            for x in range(1, 2 * m + 1):
                if index + x >= n:  
                    break
                take = piles[index] - piles[index + x]
                res = max(res, take + piles[index + x] - solve(index + x, max(m, x)))
            dp[(m, index)] = res
            return res
        
        return solve(0, 1)
