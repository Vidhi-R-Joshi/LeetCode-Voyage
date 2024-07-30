class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int[] cnt_a = new int[n + 1];
        int[] cnt_b = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            cnt_a[i] = cnt_a[i - 1] + (s.charAt(i - 1) == 'a' ? 1 : 0);
            cnt_b[i] = cnt_b[i - 1] + (s.charAt(i - 1) == 'b' ? 1 : 0);
        }

        int min_dels = Integer.MAX_VALUE;

        for (int i = 0; i <= n; i++) {
            int dels = cnt_b[i] + (cnt_a[n] - cnt_a[i]);
            min_dels = Math.min(min_dels, dels);
        }

        return min_dels;
    }
}

