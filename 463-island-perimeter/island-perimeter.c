#include <stdio.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || *gridColSize == 0) {
        return 0;
    }

    int peri = 0;

    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < *gridColSize; c++) {
            if (grid[r][c] == 1) {
                if (r == 0 || grid[r - 1][c] == 0) {
                    peri++;
                }
                if (r == gridSize - 1 || grid[r + 1][c] == 0) {
                    peri++;
                }
                if (c == 0 || grid[r][c - 1] == 0) {
                    peri++;
                }
                if (c == *gridColSize - 1 || grid[r][c + 1] == 0) {
                    peri++;
                }
            }
        }
    }

    return peri;
}

