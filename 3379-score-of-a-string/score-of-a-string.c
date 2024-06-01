#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int scoreOfString(char* s) {
    int x = 0;

    for (int i = 1; i < strlen(s); i++) {
        x += abs(s[i] - s[i - 1]);
    }

    return x;
}

