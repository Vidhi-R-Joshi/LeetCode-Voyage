#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long wonderfulSubstrings(char* word) {
    int n = strlen(word);
    int state = 0;
    int count[1 << 10] = {0};
    count[0] = 1;
    
    long ret = 0;
    for (int i = 0; i < n; i++) {
        int j = word[i] - 'a';
        state ^= (1 << j);
        
        ret += count[state];
        
        for (int k = 0; k < 10; k++)
            ret += count[state ^ (1 << k)];
        
        count[state]++;
    }
    return ret;
}

