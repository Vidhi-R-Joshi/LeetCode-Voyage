class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int x = rowSum.length;
        int y = colSum.length;
        int[][] res = new int[x][y];

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                int val = Math.min(rowSum[i], colSum[j]);
                res[i][j] = val;
                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }

        return res;
    }
}