class Solution(object):
    def appendCharacters(self, s, t):
        x, y = 0, 0
        while x < len(s) and y < len(t):
            if s[x] == t[y]:
                y += 1
            x += 1
        
        if y == len(t):
            return 0
        
        return len(t) - y
