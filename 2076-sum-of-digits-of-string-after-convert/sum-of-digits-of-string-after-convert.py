class Solution:
    def transform(self, t):
        res = 0
        while t > 0:
            res += t % 10
            t //= 10
        return res

    def getLucky(self, s, k):
        res = 0
        for ch in s:
            num = ord(ch) - ord('a') + 1
            if num >= 10:
                res += num % 10 + num // 10
            else:
                res += num

        while k > 1:
            k -= 1
            res = self.transform(res)

        return res
