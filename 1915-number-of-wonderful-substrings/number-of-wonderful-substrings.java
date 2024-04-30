import java.util.*;

public class Solution {
    public long wonderfulSubstrings(String word) {
        int n = word.length();
        int state = 0;
        int[] count = new int[1 << 10];
        count[0]++;
        
        long ret = 0;
        for (int i = 0; i < n; i++) {
            int j = word.charAt(i) - 'a';
            state ^= (1 << j);
            
            ret += count[state];
            
            for (int k = 0; k < 10; k++)
                ret += count[state ^ (1 << k)];
            
            count[state]++;
        }
        return ret;
    }
}

