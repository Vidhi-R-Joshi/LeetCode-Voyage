import java.util.*;

class Solution {
    public int[][] findFarmland(int[][] land) {
        int m = land.length, n = land[0].length;
        List<int[]> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0 || (j > 0 && land[i][j - 1] == 1) || (i > 0 && land[i - 1][j] == 1)) {
                    continue;
                }
                int x = i, y = j;
                while (x + 1 < m && land[x + 1][j] == 1) {
                    x++;
                }
                while (y + 1 < n && land[i][y + 1] == 1) {
                    y++;
                }
                res.add(new int[]{i, j, x, y});
            }
        }
        return res.toArray(new int[res.size()][]);
    }
}

