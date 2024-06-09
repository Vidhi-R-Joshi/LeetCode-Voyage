#include <stdio.h>
#include <stdlib.h>

int subarraysDivByK(int* nums, int numsSize, int k) {
    int* dp = calloc(k, sizeof(int));
    dp[0] = 1;

    int res = 0;
    int x = 0;

    for (int i = 0; i < numsSize; i++) {
        x += nums[i];
        int y = ((x % k) + k) % k;
        res += dp[y];
        dp[y]++;
    }

    free(dp);
    return res;
}

