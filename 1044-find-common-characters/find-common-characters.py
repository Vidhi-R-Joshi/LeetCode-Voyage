class Solution(object):
    def commonChars(self, words):
        if not words:
            return []
        
        cnt = Counter(words[0])

        for i in words[1:]:
            cnt &= Counter(i)

            res = []
            for j, k in cnt.items():
                res.extend([j] * k)
        
        return res
