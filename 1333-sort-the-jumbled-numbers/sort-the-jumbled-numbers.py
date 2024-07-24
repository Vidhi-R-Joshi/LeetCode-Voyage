class Solution(object):
    def sortJumbled(self, mapping, nums):
        x = {str(i): str(j) for i, j in enumerate(mapping)}

        def map_value(num):
            return int(''.join(x[digit] for digit in str(num)))
        
        return sorted(nums, key=map_value)
