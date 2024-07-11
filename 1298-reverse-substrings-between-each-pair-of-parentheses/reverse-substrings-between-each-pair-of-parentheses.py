class Solution(object):
    def reverseParentheses(self, s):
        x = []

        for i in s:
            if i == ')':
                tmp = ""
                while x[-1] != '(':
                    tmp += x.pop()
                x.pop()
                x.extend(list(tmp))
            else:
                x.append(i)
        
        return ''.join(x)
