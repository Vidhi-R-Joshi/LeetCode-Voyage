#include <stdio.h>
#include <stdlib.h>

int subsetXORSum(int* nums, int numsSize) {
    int res = 0, x = numsSize;

    for (int i = 0; i < (1 << x); i++) {
        int y = 0;

        for (int j = 0; j < x; j++) {
            if ((i >> j) % 2 == 1) {
                y ^= nums[j];
            }
        }

        res += y;
    }

    return res;
}

