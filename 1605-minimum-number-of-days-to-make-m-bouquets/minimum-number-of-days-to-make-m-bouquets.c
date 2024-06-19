#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool canMakeBouquets(int* bloomDay, int bloomDaySize, int m, int k, int day) {
    int total = 0;
    int count = 0;
    for (int i = 0; i < bloomDaySize; i++) {
        if (bloomDay[i] <= day) {
            count++;
            if (count == k) {
                total++;
                count = 0;
            }
        } else {
            count = 0;
        }
        if (total >= m) {
            return true;
        }
    }
    return false;
}

int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    if ((long long)m * k > bloomDaySize) {
        return -1;
    }

    int low = 1, high = 1e9;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canMakeBouquets(bloomDay, bloomDaySize, m, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

