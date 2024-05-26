class Solution:
    def checkRecord(self, n):
        if n == 1:
            return 3
        else:
            mod = 10**9 + 7
            al, all, anl, nal, nall, nap = 1, 0, 3, 1, 1, 2
            ans = al + all + anl + nal + nall + nap
            while n > 2:
                t1 = anl % mod
                t2 = al % mod
                t3 = (al + all + anl + nal + nall + nap) % mod
                t4 = nap % mod
                t5 = nal % mod
                t6 = (nap + nal + nall) % mod
                ans = (t1 + t2 + t3 + t4 + t5 + t6) % mod
                al, all, anl, nal, nall, nap = t1, t2, t3, t4, t5, t6
                n -= 1
            return ans
