import java.util.HashSet;
import java.util.Set;

class Solution {
    public String nearestPalindromic(String n) {
        int length = n.length();
        long num = Long.parseLong(n);

        if (num <= 10) {
            return String.valueOf(num - 1);
        }
        if (n.equals("11")) {
            return "9";
        }
        if (allNine(n)) {
            return String.valueOf(num + 2);
        }

        long halfInt = Long.parseLong(n.substring(0, (length + 1) / 2));
        Set<Long> candidates = new HashSet<>();

        candidates.add(createPalindrome(String.valueOf(halfInt), length % 2 != 0));
        candidates.add(createPalindrome(String.valueOf(halfInt - 1), length % 2 != 0));
        candidates.add(createPalindrome(String.valueOf(halfInt + 1), length % 2 != 0));
        candidates.add((long) Math.pow(10, length - 1) - 1);
        candidates.add((long) Math.pow(10, length) + 1);
        candidates.remove(num);

        Long closestPalindrome = null;
        long minDiff = Long.MAX_VALUE;

        for (Long candidate : candidates) {
            long diff = Math.abs(candidate - num);
            if (diff < minDiff || (diff == minDiff && (closestPalindrome == null || candidate < closestPalindrome))) {
                minDiff = diff;
                closestPalindrome = candidate;
            }
        }

        return String.valueOf(closestPalindrome);
    }

    private boolean allNine(String n) {
        for (char c : n.toCharArray()) {
            if (c != '9') {
                return false;
            }
        }
        return true;
    }

    private long createPalindrome(String s, boolean oddLength) {
        return Long.parseLong(s + (oddLength ? new StringBuilder(s).reverse().substring(1) : new StringBuilder(s).reverse().toString()));
    }
}

