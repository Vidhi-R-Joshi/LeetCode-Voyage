import java.util.Stack;

public class Solution {
    public String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == ')') {
                StringBuilder tmp = new StringBuilder();
                while (stack.peek() != '(') {
                    tmp.append(stack.pop());
                }
                stack.pop(); // Remove the '('
                for (char reversedChar : tmp.toString().toCharArray()) {
                    stack.push(reversedChar);
                }
            } else {
                stack.push(ch);
            }
        }

        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }

        return result.reverse().toString();
    }
}