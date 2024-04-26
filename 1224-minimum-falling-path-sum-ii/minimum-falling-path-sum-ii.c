#include <limits.h>

int minFallingPathSum(int** arr, int arrSize, int* arrColSize) {
    int** dp = (int**)malloc(arrSize * sizeof(int*));
    for (int i = 0; i < arrSize; i++) {
        dp[i] = (int*)malloc(arrSize * sizeof(int));
    }
    
    for (int i = 0; i < arrSize; i++) {
        dp[0][i] = arr[0][i];
    }
    
    for (int i = 1; i < arrSize; i++) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int min1Index = -1;
        for (int j = 0; j < arrSize; j++) {
            if (dp[i - 1][j] < min1) {
                min2 = min1;
                min1 = dp[i - 1][j];
                min1Index = j;
            } else if (dp[i - 1][j] < min2) {
                min2 = dp[i - 1][j];
            }
        }
        
        for (int j = 0; j < arrSize; j++) {
            dp[i][j] = (j != min1Index) ? min1 + arr[i][j] : min2 + arr[i][j];
        }
    }
    
    int minPathSum = INT_MAX;
    for (int j = 0; j < arrSize; j++) {
        minPathSum = (dp[arrSize - 1][j] < minPathSum) ? dp[arrSize - 1][j] : minPathSum;
    }
    
    for (int i = 0; i < arrSize; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return minPathSum;
}

