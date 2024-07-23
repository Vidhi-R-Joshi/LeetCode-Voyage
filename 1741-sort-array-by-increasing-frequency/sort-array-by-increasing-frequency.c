#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Frequency {
    int number;
    int count;
};

int compare(const void *a, const void *b) {
    struct Frequency *freqA = (struct Frequency *)a;
    struct Frequency *freqB = (struct Frequency *)b;
    if (freqA->count == freqB->count) {
        return freqB->number - freqA->number;
    }
    return freqA->count - freqB->count;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    struct Frequency freq[10000] = {0};
    int freqCount = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < freqCount; j++) {
            if (freq[j].number == nums[i]) {
                freq[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freq[freqCount].number = nums[i];
            freq[freqCount].count = 1;
            freqCount++;
        }
    }

    qsort(freq, freqCount, sizeof(struct Frequency), compare);

    int *result = (int *)malloc(numsSize * sizeof(int));
    int index = 0;
    for (int i = 0; i < freqCount; i++) {
        for (int j = 0; j < freq[i].count; j++) {
            result[index++] = freq[i].number;
        }
    }

    *returnSize = numsSize;
    return result;
}

