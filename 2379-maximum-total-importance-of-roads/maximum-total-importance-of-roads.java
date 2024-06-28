import java.util.Arrays;

class Solution {
    public long maximumImportance(int n, int[][] roads) {
        int[] degree = new int[n];
        for (int[] road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        Integer[] sortedCities = new Integer[n];
        for (int i = 0; i < n; i++) {
            sortedCities[i] = i;
        }
        Arrays.sort(sortedCities, (a, b) -> degree[b] - degree[a]);

        long[] values = new long[n];
        for (int i = 0; i < n; i++) {
            values[sortedCities[i]] = n - i;
        }

        long totalImportance = 0;
        for (int[] road : roads) {
            totalImportance += values[road[0]] + values[road[1]];
        }

        return totalImportance;
    }
}

