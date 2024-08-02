class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int o = 0;

        for (int num : nums) {
            o += num;
        }

        if (o == 0) {
            return 0;
        }

        int currentSum = 0;
        for (int i = 0; i < o; i++) {
            currentSum += nums[i];
        }

        int minSwaps = o - currentSum;

        for (int i = 1; i < n; i++) {
            currentSum = currentSum - nums[i - 1] + nums[(i + o - 1) % n];
            minSwaps = Math.min(minSwaps, o - currentSum);
        }

        return minSwaps;
    }
}
