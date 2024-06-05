#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

int min(int a, int b) {
    return a < b ? a : b;
}

char** commonChars(char** words, int wordsSize, int* returnSize) {
    if (wordsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int cnt[26] = {0};
    for (int i = 0; i < strlen(words[0]); i++) {
        cnt[words[0][i] - 'a']++;
    }
    
    for (int i = 1; i < wordsSize; i++) {
        int temp[26] = {0};
        for (int j = 0; j < strlen(words[i]); j++) {
            if (cnt[words[i][j] - 'a'] > 0) {
                temp[words[i][j] - 'a']++;
                cnt[words[i][j] - 'a']--;
            }
        }
        memcpy(cnt, temp, sizeof(temp));
    }
    
    int count = 0;
    for (int i = 0; i < 26; i++) {
        count += cnt[i];
    }
    
    char** res = (char**)malloc(count * sizeof(char*));
    *returnSize = count;
    
    int idx = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            res[idx] = (char*)malloc(2 * sizeof(char));
            res[idx][0] = 'a' + i;
            res[idx][1] = '\0';
            idx++;
        }
    }
    
    return res;
}

