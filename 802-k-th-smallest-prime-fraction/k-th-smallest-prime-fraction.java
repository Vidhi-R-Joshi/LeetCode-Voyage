import java.util.*;

class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        double low = 0, high = 1.0;

        while (low < high) {
            double mid = (low + high) / 2;
            int[] result = helper(arr, mid);

            if (k < result[0]) {
                high = mid;
            } else if (k > result[0]) {
                low = mid;
            } else {
                return new int[] {result[1], result[2]};
            }
        }

        return new int[0];
    }

    private int[] helper(int[] arr, double target) {
        int count = 0, i = 0, n = arr.length;
        int num = arr[0], den = arr[n - 1];

        for (int j = 1; j < n; j++) {
            while (i < j && arr[i] <= arr[j] * target) {
                i++;
            }
            count += i;
            if (i > 0 && (long)arr[i - 1] * den > (long)arr[j] * num) {
                num = arr[i - 1];
                den = arr[j];
            }
        }

        return new int[] {count, num, den};
    }
}

