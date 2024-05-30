#include <stdio.h>

int countTriplets(int* a, int a_size) {
    int res = 0;
    for (int i = 0; i < a_size; i++) {
        int t = a[i];
        for (int k = i + 1; k < a_size; k++) {
            t = t ^ a[k];
            if (t == 0) {
                res += (k - i);
            }
        }
    }
    return res;
}

