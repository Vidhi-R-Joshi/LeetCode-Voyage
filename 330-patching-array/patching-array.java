class Solution {
    public int minPatches(int[] nums, int n) {
        long patch = 1;
        int total = 0;
        int index = 0;

        while (patch <= n) {
            if (index < nums.length && patch >= nums[index]) {
                patch += nums[index];
                index++;
            } else {
                patch += patch;
                total++;
            }
        }

        return total;
    }
}

