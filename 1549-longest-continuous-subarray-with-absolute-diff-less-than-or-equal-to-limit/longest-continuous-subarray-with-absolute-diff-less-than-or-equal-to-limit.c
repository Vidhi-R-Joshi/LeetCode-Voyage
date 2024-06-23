// sliding window
// time: O(n)
// space: O(1)
int longestSubarray(int* nums, int numsSize, int limit)
{
    int result = 1;
    int left_i = 0;
    int min_i = 0;
    int max_i = 0;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < nums[min_i]) {
            min_i = i;
            if (nums[max_i] - nums[min_i] > limit) {
                max_i = min_i;
                left_i = min_i;
                while (nums[left_i-1] - nums[min_i] <= limit) {
                    left_i--;
                    if (nums[left_i] > nums[max_i]) {
                        max_i = left_i;
                    }
                }
            }
        }
        else if (nums[i] > nums[max_i]) {
            max_i = i;
            if (nums[max_i] - nums[min_i] > limit) {
                min_i = max_i;
                left_i = min_i;
                while (nums[max_i] - nums[left_i-1] <= limit) {
                    left_i--;
                    if (nums[left_i] < nums[min_i]) {
                        min_i = left_i;
                    }
                }
            }
        }
        if (i - left_i >= result) {
            result = i - left_i + 1;
        }
    }

    return result;
}
