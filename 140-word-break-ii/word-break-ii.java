import java.util.*;

class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> res = new ArrayList<>();
        dfs(s, wordDict, 0, new ArrayList<>(), res);
        return res;
    }

    private void dfs(String s, List<String> wordDict, int start, List<String> path, List<String> res) {
        if (start == s.length()) {
            res.add(String.join(" ", path));
            return;
        }

        for (int i = start; i < s.length(); i++) {
            String word = s.substring(start, i + 1);
            if (wordDict.contains(word)) {
                path.add(word);
                dfs(s, wordDict, i + 1, path, res);
                path.remove(path.size() - 1);
            }
        }
    }
}

