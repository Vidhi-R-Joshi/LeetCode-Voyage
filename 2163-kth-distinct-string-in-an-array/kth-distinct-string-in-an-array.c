#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* kthDistinct(char** arr, int arrSize, int k) {
    int* count = (int*)calloc(arrSize, sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                count[i]++;
            }
        }
    }
    for (int i = 0; i < arrSize; i++) {
        if (count[i] == 1 && --k == 0) {
            free(count);
            return arr[i];
        }
    }
    free(count);
    return "";
}

