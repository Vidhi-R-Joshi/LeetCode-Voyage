class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);

        long y = 0;
        int n = happiness.length, x = 0;

        while (k > 0 && happiness[n - 1 - x] - x > 0) {
            y += happiness[n - 1 - x] - x;
            k--;
            x++;
        }
        
        return y;
    }
}
