class Solution:
    def maximumHappinessSum(self, happiness, k):
        happiness.sort(reverse = True)

        x, y = 0, 0

        while (k > 0 and happiness[x] - x > 0):
            y += happiness[x] - x
            k, x = k - 1, x + 1
        
        return y