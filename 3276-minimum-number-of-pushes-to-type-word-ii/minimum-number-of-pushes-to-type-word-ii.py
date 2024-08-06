class Solution:
    def minimumPushes(self, word):
        res = 0
        cnt = 0
        freq = [0] * 26

        for c in word:
            freq[ord(c) - ord('a')] += 1

        freq.sort()

        for i in range(25, -1, -1):
            if freq[i] > 0:
                res += freq[i] * (cnt // 8 + 1)
                cnt += 1

        return res
