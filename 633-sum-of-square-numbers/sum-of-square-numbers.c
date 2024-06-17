#include <math.h>

bool judgeSquareSum(int c) {
    for (int a = 0; a <= (int) sqrt(c); a++) {
        double b = sqrt(c - a * a);
        if (b == (int) b) {
            return true;
        }
    }
    return false;
}

