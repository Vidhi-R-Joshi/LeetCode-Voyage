#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int equalSubstring(char *s, char *t, int maxCost) {
    int n = strlen(s);
    int res = 0, l = 0, cost = 0;

    for (int r = 0; r < n; r++) {
        cost += abs(s[r] - t[r]);
        while (cost > maxCost) {
            cost -= abs(s[l] - t[l]);
            l++;
        }
        res = fmax(res, r - l + 1);
    }

    return res;
}

