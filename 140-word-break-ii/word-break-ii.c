#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to join strings in a list
char* join_strings(char** strings, int count, char* separator) {
    int total_length = 0;
    for (int i = 0; i < count; i++) {
        total_length += strlen(strings[i]);
    }
    total_length += (count - 1) * strlen(separator);

    char* result = (char*)malloc((total_length + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < count; i++) {
        strcat(result, strings[i]);
        if (i < count - 1) {
            strcat(result, separator);
        }
    }

    return result;
}

void dfs(char* s, char** wordDict, int wordDictSize, int start, char** path, int pathSize, char** res, int* resSize) {
    if (start == strlen(s)) {
        res[*resSize] = join_strings(path, pathSize, " ");
        (*resSize)++;
        return;
    }

    for (int i = start; i < strlen(s); i++) {
        int wordLen = i - start + 1;
        char* word = (char*)malloc((wordLen + 1) * sizeof(char));
        strncpy(word, s + start, wordLen);
        word[wordLen] = '\0';

        int found = 0;
        for (int j = 0; j < wordDictSize; j++) {
            if (strcmp(word, wordDict[j]) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            path[pathSize] = word;
            dfs(s, wordDict, wordDictSize, i + 1, path, pathSize + 1, res, resSize);
            free(path[pathSize]);
            path[pathSize] = NULL;
        } else {
            free(word);
        }
    }
}

char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    char** res = (char**)malloc(sizeof(char*) * 1000);
    *returnSize = 0;

    char** path = (char**)malloc(sizeof(char*) * 100);
    memset(path, 0, sizeof(char*) * 100);

    dfs(s, wordDict, wordDictSize, 0, path, 0, res, returnSize);

    for (int i = 0; i < 100; i++) {
        if (path[i] != NULL) {
            free(path[i]);
        }
    }
    free(path);

    return res;
}

