class Solution(object):
    def equalSubstring(self, s, t, maxCost):
        n = len(s)
        res, l, cost = 0, 0, 0

        for r in range(n):
            cost += abs(ord(s[r]) - ord(t[r]))
            while cost > maxCost:
                cost -= abs(ord(s[l]) - ord(t[l]))
                l += 1
            res = max(res, r - l + 1)
        
        return res

        