class Solution(object):
    def removeKdigits(self, num, k):
        x = []
        for i in num:
            while k > 0 and x and x[-1] > i:
                x.pop()
                k -= 1
            x.append(i)
        
        while k > 0:
            x.pop()
            k -= 1
        
        return ''.join(x).lstrip('0') or '0'