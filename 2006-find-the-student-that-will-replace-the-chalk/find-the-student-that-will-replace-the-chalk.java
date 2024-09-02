class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long sum = 0;

        for (int i = 0; i < chalk.length; i++) {
            sum += chalk[i];
        }

        k = (int)(k % sum);
        if (k == 0) {
            return 0;
        }

        int i = 0;
        while (i < chalk.length) {
            if (k < chalk[i]) {
                return i;
            } else {
                k -= chalk[i];
                i++;
            }
        }
        return 0;
    }
}