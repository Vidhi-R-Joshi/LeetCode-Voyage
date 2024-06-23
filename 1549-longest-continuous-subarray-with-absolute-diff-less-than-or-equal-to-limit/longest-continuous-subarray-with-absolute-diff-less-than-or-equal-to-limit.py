from collections import deque

class Solution:
    def longestSubarray(self, nums, limit):
        maxq = deque()
        minq = deque()
        n = len(nums)
        j = 0
        ans = 0

        for i in range(n):
            while maxq and nums[i] > nums[maxq[-1]]:
                maxq.pop()
            maxq.append(i)
            while minq and nums[i] < nums[minq[-1]]:
                minq.pop()
            minq.append(i)
            if nums[maxq[0]] - nums[minq[0]] > limit:
                if nums[j] == nums[maxq[0]]:
                    maxq.popleft()
                if nums[j] == nums[minq[0]]:
                    minq.popleft()
                j += 1
            ans = max(ans, i - j + 1)
        return ans
