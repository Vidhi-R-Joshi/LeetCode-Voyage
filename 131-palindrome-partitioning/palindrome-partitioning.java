import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        backtracking(s, new ArrayList<>(), res);
        return res;
    }

    private boolean isPalindrome(String s) {
        return s.equals(new StringBuilder(s).reverse().toString());
    }

    private void backtracking(String s, List<String> path, List<List<String>> res) {
        if (s.isEmpty()) {
            res.add(new ArrayList<>(path));
            return;
        }

        for (int i = 1; i <= s.length(); i++) {
            String prefix = s.substring(0, i);
            if (isPalindrome(prefix)) {
                path.add(prefix);
                backtracking(s.substring(i), path, res);
                path.remove(path.size() - 1);
            }
        }
    }
}

