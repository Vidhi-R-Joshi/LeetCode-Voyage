class Solution:
    def frequencySort(self, nums):
        freq = Counter(nums)
        new_nums = list(nums)

        new_nums.sort(key=lambda n: (freq[n], -n))

        for i in range(len(nums)):
            nums[i] = new_nums[i]

        return nums
