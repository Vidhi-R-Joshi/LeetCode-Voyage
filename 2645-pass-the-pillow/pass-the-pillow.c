#include <stdio.h>

int passThePillow(int n, int time) {
    int x = time % ((n - 1) * 2);

    if (x >= n - 1) {
        int y = x - (n - 1);
        return n - y;
    } else {
        return x + 1;
    }
}

