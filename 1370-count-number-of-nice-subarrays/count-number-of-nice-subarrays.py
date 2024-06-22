class Solution(object):
    def numberOfSubarrays(self, nums, k):
        from collections import defaultdict
    
        transformed = [1 if num % 2 == 1 else 0 for num in nums]
    
        count = 0
        prefix_sum = 0
        prefix_counts = defaultdict(int)
        prefix_counts[0] = 1
    
        for num in transformed:
            prefix_sum += num
            if prefix_sum - k in prefix_counts:
                count += prefix_counts[prefix_sum - k]
            prefix_counts[prefix_sum] += 1
    
        return count
