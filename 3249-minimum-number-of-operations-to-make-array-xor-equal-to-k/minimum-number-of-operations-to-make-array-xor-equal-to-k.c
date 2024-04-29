int minOperations(int* nums, int numsSize, int k) {
    int ans = 0;
    for (int x = 0; x < numsSize; x++) {
        ans = ans ^ nums[x];
    }
    ans = ans ^ k;
    int res = 0;
    while (ans > 0) {
        if (ans & 1)
            res++;
        ans = ans >> 1;
    }
    return res;
}