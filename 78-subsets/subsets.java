import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> x = new ArrayList<>();
        x.add(new ArrayList<>());

        for (int i : nums) {
            List<List<Integer>> temp = new ArrayList<>(x);
            for (List<Integer> list : temp) {
                List<Integer> newList = new ArrayList<>(list);
                newList.add(i);
                x.add(newList);
            }
        }

        return x;
    }
}

