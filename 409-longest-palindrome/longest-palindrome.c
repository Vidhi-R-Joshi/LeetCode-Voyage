#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestPalindrome(char* s) {
    int x[128] = {0};
    for (int i = 0; s[i]; i++) {
        x[(int)s[i]]++;
    }
    
    int res = 0;
    int odd = 0;
    
    for (int i = 0; i < 128; i++) {
        res += (x[i] / 2) * 2;
        if (x[i] % 2 == 1) {
            odd = 1;
        }
    }
    
    if (odd) {
        res += 1;
    }
    
    return res;
}

