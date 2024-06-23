import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxq = new LinkedList<>();
        Deque<Integer> minq = new LinkedList<>();
        int n = nums.length;
        int j = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (!maxq.isEmpty() && nums[i] > nums[maxq.peekLast()]) {
                maxq.pollLast();
            }
            maxq.offerLast(i);
            while (!minq.isEmpty() && nums[i] < nums[minq.peekLast()]) {
                minq.pollLast();
            }
            minq.offerLast(i);
            if (nums[maxq.peekFirst()] - nums[minq.peekFirst()] > limit) {
                if (nums[j] == nums[maxq.peekFirst()]) {
                    maxq.pollFirst();
                }
                if (nums[j] == nums[minq.peekFirst()]) {
                    minq.pollFirst();
                }
                j++;
            }
            ans = Math.max(ans, i - j + 1);
        }
        return ans;
    }
}

