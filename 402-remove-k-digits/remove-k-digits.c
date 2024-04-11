#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    char* x = (char*)malloc(len * sizeof(char));
    int x_size = 0;
    
    for (int i = 0; num[i]; i++) {
        while (k > 0 && x_size > 0 && x[x_size-1] > num[i]) {
            x_size--;
            k--;
        }
        x[x_size++] = num[i];
    }
    
    while (k > 0) {
        x_size--;
        k--;
    }
    
    x[x_size] = '\0';
    
    int i = 0;
    while (x[i] == '0' && x[i+1]) {
        i++;
    }
    
    if (x[i] == '\0') {
        return "0";
    }
    
    return &x[i];
}

