class Solution(object):
    def findTheWinner(self, n, k):
        x = list(range(1, n + 1))
        index = 0

        while len(x) > 1:
            index = (index + k - 1) % len(x)
            x.pop(index)
        
        return x[0]
