#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int* count = (int*)calloc(1001, sizeof(int));
    int resultIndex = 0;

    for (int i = 0; i < nums1Size; i++) {
        count[nums1[i]]++;
    }

    for (int i = 0; i < nums2Size; i++) {
        if (count[nums2[i]] > 0) {
            result[resultIndex++] = nums2[i];
            count[nums2[i]]--;
        }
    }

    *returnSize = resultIndex;
    return result;
}

