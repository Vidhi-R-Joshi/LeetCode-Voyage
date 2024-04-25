import java.util.Arrays;

class Solution {
    public int longestIdealString(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n][27];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return rec(0, 26, s, k, dp);
    }

    private int rec(int i, int last, String s, int k, int[][] dp) {
        if (i == s.length()) {
            return 0;
        }
        if (dp[i][last] != -1) {
            return dp[i][last];
        }
        int ans = 0;
        if (last == 26 || Math.abs(s.charAt(i) - 'a' - last) <= k) {
            ans = rec(i + 1, s.charAt(i) - 'a', s, k, dp) + 1;
        }
        ans = Math.max(ans, rec(i + 1, last, s, k, dp));
        dp[i][last] = ans;
        return ans;
    }
}

