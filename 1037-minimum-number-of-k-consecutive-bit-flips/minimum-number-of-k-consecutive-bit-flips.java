class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int[] z = new int[n];
        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                y ^= z[i - k];
            }

            if (nums[i] == y) {
                if (i + k > n) {
                    return -1;
                }
                x++;
                y ^= 1;
                if (i < n) {
                    z[i] = 1;
                }
            }
        }

        return x;
    }
}

