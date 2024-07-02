import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> x = new HashMap<>();

        for (int i : nums1) {
            x.put(i, x.getOrDefault(i, 0) + 1);
        }

        ArrayList<Integer> y = new ArrayList<>();

        for (int i : nums2) {
            if (x.containsKey(i) && x.get(i) > 0) {
                y.add(i);
                x.put(i, x.get(i) - 1);
            }
        }

        int[] result = new int[y.size()];
        for (int i = 0; i < y.size(); i++) {
            result[i] = y.get(i);
        }
        return result;
    }
}

