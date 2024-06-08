class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        if (nums.length == 0) {
            return false;
        }

        int x = 0;
        Map<Integer, Integer> y = new HashMap<>();
        y.put(0, -1);

        for (int i = 0; i < nums.length; i++) {
            x += nums[i];
            int z = (k == 0) ? x : x % k;

            if (y.containsKey(z)) {
                if (i - y.get(z) > 1) {
                    return true;
                }
            } else {
                y.put(z, i);
            }
        }

        return false;
    }
}

