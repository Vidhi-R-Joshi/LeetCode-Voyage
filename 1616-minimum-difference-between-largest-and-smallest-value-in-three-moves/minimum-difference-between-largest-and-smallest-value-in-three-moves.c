int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int minDifference(int* nums, int numsSize) {
    if (numsSize <= 3)
        return (0);
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int min = INT_MAX;
    while (i < 4)
    {
        if (nums[numsSize - 4 + i] - nums[i] < min)
            min = nums[numsSize - 4 + i] - nums[i];
        i++;
    }
    return (min);
}