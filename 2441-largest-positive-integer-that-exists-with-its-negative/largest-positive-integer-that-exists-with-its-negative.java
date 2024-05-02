class Solution {
    public int findMaxK(int[] nums) {
        Set<Integer> n = new HashSet<>();
        for (int num : nums) {
            n.add(num);
        }
        int x = -1;
        for (int i : nums) {
            if (n.contains(-i)) {
                x = Math.max(x, Math.abs(i));
            }
        }
        return x == -1 ? -1 : x;
    }
}

