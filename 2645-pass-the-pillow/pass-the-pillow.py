class Solution(object):
    def passThePillow(self, n, time):
        x = time % ((n - 1) * 2)

        if x >= n - 1:
            y = x - (n - 1)
            return n - y
        else:
            return x + 1
