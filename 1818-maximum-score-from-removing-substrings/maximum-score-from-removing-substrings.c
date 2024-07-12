#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *remainingString;
    int points;
} Result;

Result removeSubstring(char *s, const char *sub, int points) {
    int len = strlen(s);
    int subLen = strlen(sub);
    char *stack = (char *)malloc((len + 1) * sizeof(char));
    int top = 0;
    int score = 0;

    for (int i = 0; i < len; ++i) {
        stack[top++] = s[i];
        if (top >= subLen && strncmp(stack + top - subLen, sub, subLen) == 0) {
            top -= subLen;
            score += points;
        }
    }

    stack[top] = '\0';
    Result result;
    result.remainingString = stack;
    result.points = score;
    return result;
}

int removeSubstrings(char *s, const char *primary, int primaryPoints, const char *secondary, int secondaryPoints) {
    Result primaryResult = removeSubstring(s, primary, primaryPoints);
    Result secondaryResult = removeSubstring(primaryResult.remainingString, secondary, secondaryPoints);
    free(primaryResult.remainingString);
    int totalPoints = primaryResult.points + secondaryResult.points;
    free(secondaryResult.remainingString);
    return totalPoints;
}

int maximumGain(char *s, int x, int y) {
    if (x > y) {
        return removeSubstrings(s, "ab", x, "ba", y);
    } else {
        return removeSubstrings(s, "ba", y, "ab", x);
    }
}
