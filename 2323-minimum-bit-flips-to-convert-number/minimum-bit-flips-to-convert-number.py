class Solution(object):
    def minBitFlips(self, start, goal):
        cnt = 0
        x = start ^ goal
        while x > 0:
            if x & 1:
                cnt += 1
            x >>= 1
        return cnt
