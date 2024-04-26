class Solution {
    public int minFallingPathSum(int[][] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = arr[0][i];
        }
        
        for (int i = 1; i < n; i++) {
            int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
            int min1Index = -1;
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i - 1][j];
                    min1Index = j;
                } else if (dp[i - 1][j] < min2) {
                    min2 = dp[i - 1][j];
                }
            }
            
            for (int j = 0; j < n; j++) {
                dp[i][j] = (j != min1Index) ? min1 + arr[i][j] : min2 + arr[i][j];
            }
        }
        
        int minPathSum = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            minPathSum = Math.min(minPathSum, dp[n - 1][j]);
        }
        
        return minPathSum;
    }
}
