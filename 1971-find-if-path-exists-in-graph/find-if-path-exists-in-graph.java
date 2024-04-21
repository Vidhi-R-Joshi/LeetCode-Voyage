import java.util.*;

class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, List<Integer>> g = new HashMap<>();
        for (int i = 0; i < n; i++) {
            g.put(i, new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            g.get(u).add(v);
            g.get(v).add(u);
        }

        Set<Integer> visited = new HashSet<>();
        Deque<Integer> q = new LinkedList<>();
        q.offerLast(source);

        while (!q.isEmpty()) {
            int curr = q.pollFirst();
            if (curr == destination) {
                return true;
            }
            visited.add(curr);
            for (int i : g.get(curr)) {
                if (!visited.contains(i)) {
                    visited.add(i);
                    q.offerLast(i);
                }
            }
        }

        return false;
    }
}

