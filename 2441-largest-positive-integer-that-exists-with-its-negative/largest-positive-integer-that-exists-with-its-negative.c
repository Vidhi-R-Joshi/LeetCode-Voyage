#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int findMaxK(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int ans = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            for (int j = 0; j < numsSize; j++) {
                if (nums[j] == -nums[i]) {
                    ans = (nums[i] > ans) ? nums[i] : ans;
                    break;
                }
            }
        }
    }
    return ans;
}

