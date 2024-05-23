class Solution:
    def beautifulSubsets(self, nums, k):
        def f(nums, b, i):
            if i < len(nums):
                result = f(nums, b, i+1)
                if nums[i]-k not in b:
                    result += f(nums, b+[nums[i]], i+1)

                return result

            return len(b) > 0
        
        return f(sorted(nums), [], 0)
