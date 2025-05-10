class Solution(object):
    def minSum(self, nums1, nums2):
        sum1, sum2 = 0,0
        z1, z2 = 0,0

        for num in nums1:
            if num == 0:
                z1 += 1
            sum1 += num
        
        for num in nums2:
            if num == 0:
                z2 += 1
            sum2 += num
        
        if z1 == 0 and z2 == 0:
            return sum1 if sum1 == sum2 else -1
        elif z1 == 0:
            return sum1 if sum2 + z2 <= sum1 else -1
        elif z2 == 0:
            return sum2 if sum1 + z1 <= sum2 else -1
        
        return max(sum1 + z1, sum2 + z2)