class Solution(object):
    def longestSubarray(self, nums):
        max_num = 0
        c = 0
        m = 0
        for i in nums:
            if max_num < i:
                max_num = i
        for i in nums:
            if i == max_num:
                c += 1
            else:
                c = 0
            if c > m:
                m = c
        return m
