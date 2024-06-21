#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int x = 0;
    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i] == 0) {
            x += customers[i];
        }
    }
    int y = 0;
    int z = 0;
    for (int i = 0; i < customersSize; i++) {
        z += grumpy[i] == 1 ? customers[i] : 0;
        if (i >= minutes) {
            z -= grumpy[i - minutes] == 1 ? customers[i - minutes] : 0;
        }
        y = fmax(y, z);
    }
    return x + y;
}

