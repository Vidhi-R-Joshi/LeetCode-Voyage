class Solution {
    public int appendCharacters(String s, String t) {
        int x = 0, y = 0;
        while (x < s.length() && y < t.length()) {
            if (s.charAt(x) == t.charAt(y)) {
                y++;
            }
            x++;
        }
        
        if (y == t.length()) {
            return 0;
        }
        
        return t.length() - y;
    }
}

