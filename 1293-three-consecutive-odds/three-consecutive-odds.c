#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    int cnt = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            cnt++;
        } else {
            cnt = 0;
        }
        if (cnt == 3) {
            return true;
        }
    }

    return false;
}

