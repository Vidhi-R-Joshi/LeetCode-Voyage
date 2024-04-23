import java.util.*;

class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        if (n == 1) {
            res.add(0);
            return res;
        }
        
        if (edges.length == 0) {
            for (int i = 0; i < n; i++) {
                res.add(i);
            }
            return res;
        }
        
        Map<Integer, Set<Integer>> x = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!x.containsKey(u)) {
                x.put(u, new HashSet<>());
            }
            x.get(u).add(v);
            if (!x.containsKey(v)) {
                x.put(v, new HashSet<>());
            }
            x.get(v).add(u);
        }
        
        for (int i : x.keySet()) {
            if (x.get(i).size() == 1) {
                res.add(i);
            }
        }
        
        while (n > 2) {
            n -= res.size();
            List<Integer> y = new ArrayList<>();
            for (int k : res) {
                int u = x.get(k).iterator().next();
                x.get(u).remove(k);
                if (x.get(u).size() == 1) {
                    y.add(u);
                }
            }
            res = y;
        }
        
        return res;
    }
}

