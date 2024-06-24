#include <stdio.h>
#include <stdlib.h>

int minKBitFlips(int* nums, int numsSize, int k) {
    int flip_count = 0;
    int flipped = 0;
    int *is_flipped = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (i >= k) {
            flipped ^= is_flipped[i - k];
        }

        if (nums[i] == flipped) {
            if (i + k > numsSize) {
                free(is_flipped);
                return -1;
            }
            flip_count++;
            flipped ^= 1;
            is_flipped[i] = 1;
        }
    }

    free(is_flipped);
    return flip_count;
}
