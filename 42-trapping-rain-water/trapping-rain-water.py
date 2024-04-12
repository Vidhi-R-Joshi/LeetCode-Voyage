class Solution(object):
    def trap(self, height):
        if not height:
            return 0
        
        l, r = 0, len(height) - 1
        lmax, rmax = height[l], height[r]
        res = 0

        while l < r:
            lmax, rmax = max(height[l], lmax), max(height[r], rmax)

            if lmax <= rmax:
                res += lmax - height[l]
                l += 1
            else:
                res += rmax - height[r]
                r -= 1
        
        return res