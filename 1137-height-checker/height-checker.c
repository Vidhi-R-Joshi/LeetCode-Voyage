#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int heightChecker(int* heights, int heightsSize) {
    int cnt = 0;
    int* expected = (int*)malloc(heightsSize * sizeof(int));
    for (int i = 0; i < heightsSize; i++) {
        expected[i] = heights[i];
    }
    qsort(expected, heightsSize, sizeof(int), (int(*)(const void*, const void*))compare);

    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != expected[i]) {
            cnt++;
        }
    }

    free(expected);
    return cnt;
}

