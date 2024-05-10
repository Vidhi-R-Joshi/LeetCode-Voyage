/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpFunc(const void* a, const void* b) { 
    return (*(int*)a) - (*(int*)b);
    }
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * 2);
    if (k == 1) {
        res[0] = arr[0];
        res[1] = arr[arrSize - 1];
        return res;
        free(res);
    }
    int l = ((arrSize - 1) * arrSize) / 2;
    float ar[l];
    l = 0;
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; ++j)
            ar[l++] = (float)arr[i] / (float)arr[j];
    }
    qsort(ar, l, sizeof(int), cmpFunc);
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++)
            if ((float)arr[i] / (float)arr[j] == ar[k - 1]) {
                res[0] = arr[i];
                res[1] = arr[j];
                return res;
            }
    }
    return res;
    free(res);
}