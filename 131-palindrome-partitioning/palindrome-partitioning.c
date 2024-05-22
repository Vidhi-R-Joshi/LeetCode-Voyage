/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#define PSIZE 16
#define PSIZE2 32768

int isPalindrome(char* s, int i, int j) {
    while (i <= j) {
        if (s[i++] != s[--j]) {
            return 0;
        }
    }
    return 1;
}

char* slice(char* s, int i, int j) {
    char* part = (char*)calloc((j - i + 1), sizeof(char));
    strncpy(part, s + i, j - i);
    return part;
}

char** rowDup(char** s, int n) {
    char** newRow = (char**)malloc(PSIZE * sizeof(char*));
    for (int i = 0; i < n; ++i) {
        newRow[i] = s[i];
    }
    return newRow;
}

void backTrack(char* s, int i, int len, int parts, int row, char*** ans,
               int* ansSize, int* cols) {
    int j, n;
    char** nxt;
    if (i >= len) {
        cols[row] = parts;
        return;
    }
    ans[row][parts] = slice(s, i, i + 1);
    backTrack(s, i + 1, len, parts + 1, row, ans, ansSize, cols);
    for (j = i + 2; j <= len; ++j) {
        if (!isPalindrome(s, i, j))
            continue;
        nxt = rowDup(ans[row], parts);
        n = *ansSize;
        *ansSize += 1;
        nxt[parts] = slice(s, i, j);
        ans[n] = nxt;
        backTrack(s, j, len, parts + 1, n, ans, ansSize, cols);
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    char*** ans = (char***)malloc(PSIZE2 * sizeof(char**));
    int* colSizes = (int*)malloc(PSIZE2 * sizeof(int));
    int ansLen = 1, n = strlen(s);
    ans[0] = (char**)malloc(PSIZE * sizeof(char*));
    backTrack(s, 0, n, 0, 0, ans, &ansLen, colSizes);
    printf("%d\n", ansLen);
    *returnSize = ansLen;
    *returnColumnSizes = colSizes;
    return ans;
}