class Solution {
    public String removeKdigits(String num, int k) {
        List<Character> x = new ArrayList<>();
        for (char c : num.toCharArray()) {
            while (k > 0 && !x.isEmpty() && x.get(x.size() - 1) > c) {
                x.remove(x.size() - 1);
                k--;
            }
            x.add(c);
        }
        
        while (k > 0) {
            x.remove(x.size() - 1);
            k--;
        }
        
        StringBuilder sb = new StringBuilder();
        for (char c : x) {
            sb.append(c);
        }
        
        String result = sb.toString().replaceFirst("^0+(?!$)", "");
        return result.isEmpty() ? "0" : result;
    }
}

