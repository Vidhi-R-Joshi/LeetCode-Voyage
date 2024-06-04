import java.util.HashMap;

class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> x = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            x.put(c, x.getOrDefault(c, 0) + 1);
        }
        
        int res = 0;
        boolean odd = false;
        
        for (int i : x.values()) {
            res += (i / 2) * 2;
            if (i % 2 == 1) {
                odd = true;
            }
        }
        
        if (odd) {
            res += 1;
        }
        
        return res;
    }
}

