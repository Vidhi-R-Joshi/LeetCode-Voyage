#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int findRotateSteps(char* ring, char* key) {
    int n = strlen(ring);
    int m = strlen(key);
    int dp[m + 1][n];
    memset(dp, 0, sizeof(dp));
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MAX;
            for (int k = 0; k < n; k++) {
                if (ring[k] == key[i]) {
                    int diff = abs(j - k);
                    int step = fmin(diff, n - diff);
                    dp[i][j] = fmin(dp[i][j], step + dp[i + 1][k]);
                }
            }
        }
    }
    
    return dp[0][0] + m;
}

