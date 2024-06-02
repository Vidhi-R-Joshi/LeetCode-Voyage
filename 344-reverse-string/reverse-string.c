void reverseString(char* s, int sSize) {
    int x = 0, y = sSize - 1;
    while (x < y) {
        char temp = s[x];
        s[x] = s[y];
        s[y] = temp;
        x++;
        y--;
    }
}

