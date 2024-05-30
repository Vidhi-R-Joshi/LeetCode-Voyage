import java.util.*;

class Solution {
    public int countTriplets(int[] arr) {
        Map<Integer, List<Integer>> x = new HashMap<>();
        int y = 0;
        x.put(0, new ArrayList<>());
        x.get(0).add(-1);
        int res = 0;

        for (int i = 0; i < arr.length; i++) {
            y ^= arr[i];

            for (int k : x.getOrDefault(y, new ArrayList<>())) {
                res += (i - k - 1);
            }
            x.computeIfAbsent(y, k -> new ArrayList<>()).add(i);
        }

        return res;
    }
}

