#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int specialArray(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int prev = -1;
    for (int i = 0; i < numsSize; i++) {
        if (numsSize - i <= nums[i] && numsSize - i > prev) {
            return numsSize - i;
        }
        prev = nums[i];
    }
    return -1;
}

