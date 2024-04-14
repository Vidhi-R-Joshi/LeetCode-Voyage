#include <stdio.h>

int trap(int* height, int heightSize) {
    if (heightSize == 0) {
        return 0;
    }
    
    int l = 0, r = heightSize - 1;
    int lmax = height[l], rmax = height[r];
    int res = 0;

    while (l < r) {
        lmax = (height[l] > lmax) ? height[l] : lmax;
        rmax = (height[r] > rmax) ? height[r] : rmax;

        if (lmax <= rmax) {
            res += lmax - height[l];
            l++;
        } else {
            res += rmax - height[r];
            r--;
        }
    }
    
    return res;
}

