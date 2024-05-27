class Solution {
    public int specialArray(int[] nums) {
        int n = nums.length;
        int prev = -1;
        Arrays.sort(nums);

        for (int i = 0; i < n; i++) {
            if (n - i <= nums[i] && n - i > prev) {
                return n - i;
            }
            prev = nums[i];
        }

        return -1;
    }
}

