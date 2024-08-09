class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int count = 0;
        for (int i = 0; i < grid.length - 2; i++) {
            for (int j = 0; j < grid[0].length - 2; j++) {
                int[][] square = new int[3][3];
                for (int row = 0; row < 3; row++) {
                    System.arraycopy(grid[i + row], j, square[row], 0, 3);
                }
                if (isMagic(square)) {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean isMagic(int[][] square) {
        int[] values = new int[9];
        for (int i = 0; i < 3; i++) {
            System.arraycopy(square[i], 0, values, i * 3, 3);
        }
        Arrays.sort(values);
        for (int i = 0; i < 9; i++) {
            if (values[i] != i + 1) {
                return false;
            }
        }

        int expectedSum = Arrays.stream(square[0]).sum();
        for (int[] row : square) {
            if (Arrays.stream(row).sum() != expectedSum) {
                return false;
            }
        }
        for (int col = 0; col < 3; col++) {
            if (square[0][col] + square[1][col] + square[2][col] != expectedSum) {
                return false;
            }
        }
        if (square[0][0] + square[1][1] + square[2][2] != expectedSum) {
            return false;
        }
        if (square[0][2] + square[1][1] + square[2][0] != expectedSum) {
            return false;
        }

        return true;
    }
}

