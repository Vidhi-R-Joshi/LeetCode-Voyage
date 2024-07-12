class Solution(object):
    def maximumGain(self, s, x, y):
        if x > y:
            primary, secondary = "ab", "ba"
            primary_points, secondary_points = x, y
        else:
            primary, secondary = "ba", "ab"
            primary_points, secondary_points = y, x

        def remove_substring(s, sub, points):
            stack = []
            score = 0
            for char in s:
                if stack and stack[-1] + char == sub:
                    stack.pop()
                    score += points
                else:
                    stack.append(char)
            
            return "".join(stack), score

        s, score_primary = remove_substring(s, primary, primary_points)
        _, score_secondary = remove_substring(s, secondary, secondary_points)

        return score_primary + score_secondary
