class Solution {
    public int findCenter(int[][] edges) {
        int n = edges.length + 1;
        List<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i < n + 1; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
        }

        for (int i = 1; i < n + 1; i++) {
            if (graph[i].size() == n - 1) {
                return i;
            }
        }

        return -1;
    }
}

