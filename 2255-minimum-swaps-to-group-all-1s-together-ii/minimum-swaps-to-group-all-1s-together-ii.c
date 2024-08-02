int minSwaps(int* nums, int numsSize) {
    int o = 0;

    for (int i = 0; i < numsSize; i++) {
        o += nums[i];
    }

    if (o == 0) {
        return 0;
    }

    int currentSum = 0;
    for (int i = 0; i < o; i++) {
        currentSum += nums[i];
    }

    int minSwaps = o - currentSum;

    for (int i = 1; i < numsSize; i++) {
        currentSum = currentSum - nums[i - 1] + nums[(i + o - 1) % numsSize];
        if (o - currentSum < minSwaps) {
            minSwaps = o - currentSum;
        }
    }

    return minSwaps;
}