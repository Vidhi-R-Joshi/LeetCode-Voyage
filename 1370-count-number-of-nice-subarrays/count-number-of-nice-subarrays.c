int subArrayAtLeastK(int *nums, int numsSize, int k) {
    int i, j=0, count=0, odds=0;
    for (i = 0; i < numsSize; ++i) {
        odds += (nums[i] & 1);
        while(odds == k) {
            count += numsSize - i;
            odds -= (nums[j++] & 1);
        }
    }
    return count;
}

int numberOfSubarrays(int* nums, int numsSize, int k) {
    return subArrayAtLeastK(nums, numsSize, k) - 
           subArrayAtLeastK(nums, numsSize, k+1);
}