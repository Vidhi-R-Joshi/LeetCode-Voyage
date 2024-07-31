import java.util.Arrays;

class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int n = books.length;
        int[] f = new int[n + 1];
        Arrays.fill(f, Integer.MAX_VALUE);
        f[0] = 0;

        for (int i = 1; i <= n; i++) {
            int w = books[i - 1][0];
            int h = books[i - 1][1];
            f[i] = f[i - 1] + h;

            for (int j = i - 1; j > 0; j--) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = Math.max(h, books[j - 1][1]);
                f[i] = Math.min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
}

