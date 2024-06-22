import java.util.HashMap;

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int count = 0;
        int prefixSum = 0;
        HashMap<Integer, Integer> prefixCounts = new HashMap<>();
        prefixCounts.put(0, 1);

        for (int num : nums) {
            prefixSum += (num % 2 == 1) ? 1 : 0;
            if (prefixSum - k >= 0 && prefixCounts.containsKey(prefixSum - k)) {
                count += prefixCounts.get(prefixSum - k);
            }
            prefixCounts.put(prefixSum, prefixCounts.getOrDefault(prefixSum, 0) + 1);
        }

        return count;
    }
}

