class Solution(object):
    def countConsistentStrings(self, allowed, words):
        x = set(allowed)
        cnt = 0
        for i in words:
            y = True
            for j in i:
                if j not in x:
                    y = False
                    break
            if y:
                cnt += 1
        return cnt
       