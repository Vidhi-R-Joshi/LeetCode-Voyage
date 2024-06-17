import java.lang.Math;

class Solution {
    public boolean judgeSquareSum(int c) {
        for (int a = 0; a <= (int) Math.sqrt(c); a++) {
            double b = Math.sqrt(c - a * a);
            if (b == (int) b) {
                return true;
            }
        }
        return false;
    }
}

