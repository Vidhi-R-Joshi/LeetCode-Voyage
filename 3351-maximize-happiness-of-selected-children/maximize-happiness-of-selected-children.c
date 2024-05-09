#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    qsort(happiness, happinessSize, sizeof(int), (int(*)(const void*, const void*))compare);

    long y = 0;
    int x = 0;

    while (k > 0 && happiness[happinessSize - 1 - x] - x > 0) {
        y += happiness[happinessSize - 1 - x] - x;
        k--;
        x++;
    }

    return y;
}



