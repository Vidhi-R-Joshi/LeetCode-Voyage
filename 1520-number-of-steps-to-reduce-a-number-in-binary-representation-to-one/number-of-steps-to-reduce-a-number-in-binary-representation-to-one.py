class Solution(object):
    def numSteps(self, s):
        s = int(s, 2)
        cnt = 0

        while s != 1:
            if s % 2 == 0:
                s //= 2
            else:
                s += 1
            cnt += 1
        
        return cnt
