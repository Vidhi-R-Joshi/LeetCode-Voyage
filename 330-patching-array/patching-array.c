#include <stdio.h>

int minPatches(int* nums, int numsSize, int n) {
    long long patch = 1;
    int total = 0;
    int index = 0;

    while (patch <= n) {
        if (index < numsSize && patch >= nums[index]) {
            patch += nums[index];
            index++;
        } else {
            patch += patch;
            total++;
        }
    }

    return total;
}

