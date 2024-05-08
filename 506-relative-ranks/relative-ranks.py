class Solution(object):
    def findRelativeRanks(self, score):
        s = len(score)

        index = list(range(s))
        index.sort(key = lambda x : - score[x])

        top3 = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        
        answer = [None] * s

        for i, j in enumerate(index):
            if i < 3:
                answer[j] = top3[i]
            else:
                answer[j] = str(i + 1)
        
        return answer