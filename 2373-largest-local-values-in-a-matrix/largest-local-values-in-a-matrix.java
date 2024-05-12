class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] maxLocal = new int[n - 2][n - 2];
        
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                int[][] subMatrix = new int[3][3];
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        subMatrix[k][l] = grid[i - 1 + k][j - 1 + l];
                    }
                }
                int max = Integer.MIN_VALUE;
                for (int[] row : subMatrix) {
                    for (int val : row) {
                        max = Math.max(max, val);
                    }
                }
                maxLocal[i - 1][j - 1] = max;
            }
        }
        
        return maxLocal;
    }
}

