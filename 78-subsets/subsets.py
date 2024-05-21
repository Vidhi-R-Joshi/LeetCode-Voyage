class Solution(object):
    def subsets(self, nums):
        x = [[]]

        for i in nums:
            x += [j + [i] for j in x]
        
        return x
        