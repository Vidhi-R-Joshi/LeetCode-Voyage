#include <stdio.h>
#include <string.h>

int appendCharacters(char* s, char* t) {
    int x = 0, y = 0;
    while (x < strlen(s) && y < strlen(t)) {
        if (s[x] == t[y]) {
            y++;
        }
        x++;
    }
    
    if (y == strlen(t)) {
        return 0;
    }
    
    return strlen(t) - y;
}

