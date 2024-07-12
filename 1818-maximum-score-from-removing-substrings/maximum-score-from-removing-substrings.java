public class Solution {

    public static int maximumGain(String s, int x, int y) {
        if (x > y) {
            return removeSubstrings(s, "ab", x, "ba", y);
        } else {
            return removeSubstrings(s, "ba", y, "ab", x);
        }
    }

    private static int removeSubstrings(String s, String primary, int primaryPoints, String secondary, int secondaryPoints) {
        Result primaryResult = removeSubstring(s, primary, primaryPoints);
        Result secondaryResult = removeSubstring(primaryResult.remainingString, secondary, secondaryPoints);
        return primaryResult.points + secondaryResult.points;
    }

    private static class Result {
        String remainingString;
        int points;

        Result(String remainingString, int points) {
            this.remainingString = remainingString;
            this.points = points;
        }
    }

    private static Result removeSubstring(String s, String sub, int points) {
        StringBuilder stack = new StringBuilder();
        int score = 0;
        for (char c : s.toCharArray()) {
            stack.append(c);
            int len = stack.length();
            if (len >= 2 && stack.substring(len - 2).equals(sub)) {
                stack.delete(len - 2, len);
                score += points;
            }
        }
        return new Result(stack.toString(), score);
    }
}
