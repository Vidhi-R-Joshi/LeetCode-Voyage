class Solution(object):
    def reverseString(self, s):
        x, y = 0, len(s) - 1
        while x < y:
            s[x], s[y] = s[y], s[x]
            x += 1
            y -= 1
        
        return s
