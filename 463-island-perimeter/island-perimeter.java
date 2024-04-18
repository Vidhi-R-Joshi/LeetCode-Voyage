class Solution {
    public int islandPerimeter(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        
        int rows = grid.length;
        int cols = grid[0].length;
        int peri = 0;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    if (r == 0 || grid[r - 1][c] == 0) {
                        peri++;
                    }
                    if (r == rows - 1 || grid[r + 1][c] == 0) {
                        peri++;
                    }
                    if (c == 0 || grid[r][c - 1] == 0) {
                        peri++;
                    }
                    if (c == cols - 1 || grid[r][c + 1] == 0) {
                        peri++;
                    }
                }
            }
        }
        
        return peri;
    }
}

