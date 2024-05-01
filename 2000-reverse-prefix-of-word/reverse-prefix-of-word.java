class Solution {
    public String reversePrefix(String word, char ch) {
        if (!word.contains(String.valueOf(ch))) {
            return word;
        }
        
        int x = word.indexOf(ch);
        String rev = new StringBuilder(word.substring(0, x + 1)).reverse().toString();
        return word.replaceFirst(word.substring(0, x + 1), rev);
    }
}

