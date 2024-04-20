#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the inner arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *returnColumnSizes array must be malloced, assume caller calls free().
 */
int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes) {
    int m = landSize, n = *landColSize;
    int** res = (int**)malloc(sizeof(int*) * m * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m * n);
    *returnSize = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] == 0 || (j > 0 && land[i][j - 1] == 1) || (i > 0 && land[i - 1][j] == 1)) {
                continue;
            }
            int x = i, y = j;
            while (x + 1 < m && land[x + 1][j] == 1) {
                x++;
            }
            while (y + 1 < n && land[x][y + 1] == 1) {
                y++;
            }
            res[*returnSize] = (int*)malloc(sizeof(int) * 4);
            res[*returnSize][0] = i;
            res[*returnSize][1] = j;
            res[*returnSize][2] = x;
            res[*returnSize][3] = y;
            (*returnColumnSizes)[*returnSize] = 4;
            (*returnSize)++;
        }
    }
    
    return res;
}

