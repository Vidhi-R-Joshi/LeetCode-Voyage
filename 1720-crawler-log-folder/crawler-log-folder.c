#include <stdio.h>
#include <string.h>

int minOperations(char* logs[], int logsSize) {
    int ans = 0;

    for (int i = 0; i < logsSize; i++) {
        if (strcmp(logs[i], "./") == 0)
            continue;
        if (strcmp(logs[i], "../") == 0)
            ans = (ans > 0) ? ans - 1 : 0;
        else
            ans++;
    }

    return ans;
}

