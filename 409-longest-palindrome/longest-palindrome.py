class Solution(object):
    def longestPalindrome(self, s):
        x = Counter(s)
        res = 0
        odd = False

        for i in x.values():
             res += (i // 2) * 2
             if i % 2 == 1:
                odd = True
        
        if odd:
            res += 1
        
        return res
