#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int** arr = (int**)malloc((gridSize - 2) * sizeof(int*));
    for (int i = 0; i < gridSize - 2; i++) {
        arr[i] = (int*)malloc((gridSize - 2) * sizeof(int));
    }
    int arrSize = gridSize - 2;
    *returnSize = arrSize;
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            arr[i][j] = maxElement(grid, i, j);
        }
    }
    *returnColumnSizes = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        (*returnColumnSizes)[i] = arrSize;
    }
    return arr;
}

int maxElement(int** grid, int r, int c) {
    int max = INT_MIN;
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            max = fmax(grid[i][j], max);
        }
    }
    return max;
}