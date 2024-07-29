class Solution(object):
    def numTeams(self, rating):
        n = len(rating)
        cnt = 0

        for j in range(1, n - 1):
            ls = ll = rs = rl = 0

            for i in range(j):
                if rating[i] < rating[j]:
                    ls += 1
                else:
                    ll += 1

            for k in range(j + 1, n):
                if rating[k] < rating[j]:
                    rs += 1
                else:
                    rl += 1

            cnt += ls * rl + ll * rs

        return cnt
