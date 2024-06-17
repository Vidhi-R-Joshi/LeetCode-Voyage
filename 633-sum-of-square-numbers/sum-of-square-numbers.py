class Solution(object):
    def judgeSquareSum(self, c):
        for a in range(0, int(math.sqrt(c)) + 1):
            b = math.sqrt(c - a * a)
            if b == int(b):
                return True
        return False
