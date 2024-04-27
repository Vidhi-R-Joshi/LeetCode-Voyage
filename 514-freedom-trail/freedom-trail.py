class Solution:
    def findRotateSteps(self, ring, key):
        n = len(ring)
        s = [float('inf')] * n
        ss = [float('inf')] * n
        s[0] = 0
        for c in key:
            ss = [float('inf')] * n
            for i in range(n):
                if ring[i] == c:
                    for j in range(n):
                        ss[i] = min(ss[i], s[j] + min(abs(i-j), n-abs(i-j)))
            s, ss = ss, s
        return len(key) + min(s)

