class Solution(object):
    def intersect(self, nums1, nums2):
        x = {}

        for i in nums1:
            x[i] = x.get(i, 0) + 1
        
        y = []

        for i in nums2:
            if i in x and x[i] > 0:
                y.append(i)
                x[i] -= 1
        
        return y
