#include <stdio.h>
#include <string.h>

int numSteps(char* s) {
    int l = strlen(s) - 1;
    int carry = 0;
    int count = 0;
    
    while (l > 0) {
        if (s[l] - '0' + carry == 0) {
            carry = 0;
            count++;
        } else if (s[l] - '0' + carry == 2) {
            carry = 1;
            count++;
        } else {
            carry = 1;
            count += 2;
        }
        l--;
    }
    
    if (carry == 1) {
        count++;
    }
    
    return count;
}

