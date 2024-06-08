class Solution():
    def checkSubarraySum(self, nums, k):
      if not nums:
        return False

      x = 0
      y = {0: -1}

      for i in range(len(nums)):
        x += nums[i]
        z = x % k

        if z in y:
            if i - y[z] > 1:
                return True
        else:
            y[z] = i

      return False
