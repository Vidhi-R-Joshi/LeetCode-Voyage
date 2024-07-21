import java.util.*;

class Solution {
    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        List<Integer> row = f(rowConditions, k);
        List<Integer> col = f(colConditions, k);
        if (row == null || col == null) {
            return new int[0][0];
        }
        int[][] ans = new int[k][k];
        int[] m = new int[k + 1];
        Arrays.fill(m, -1);
        for (int i = 0; i < col.size(); i++) {
            m[col.get(i)] = i;
        }
        for (int i = 0; i < row.size(); i++) {
            ans[i][m[row.get(i)]] = row.get(i);
        }
        return ans;
    }

    private List<Integer> f(int[][] cond, int k) {
        List<Integer> res = new ArrayList<>();
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i <= k; i++) {
            g.add(new ArrayList<>());
        }
        int[] indeg = new int[k + 1];
        for (int[] pair : cond) {
            int a = pair[0], b = pair[1];
            g.get(a).add(b);
            indeg[b]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= k; i++) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            for (int x = 0; x < q.size(); x++) {
                int i = q.poll();
                res.add(i);
                for (int j : g.get(i)) {
                    indeg[j]--;
                    if (indeg[j] == 0) {
                        q.offer(j);
                    }
                }
            }
        }
        return res.size() != k ? null : res;
    }
}

