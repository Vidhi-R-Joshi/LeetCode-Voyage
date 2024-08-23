from fractions import Fraction
class Solution(object):
    def fractionAddition(self, expression):
        result = Fraction(0, 1)
        i = 0
        n = len(expression)
        
        while i < n:
            sign = 1
            if expression[i] == '-':
                sign = -1
                i += 1
            elif expression[i] == '+':
                i += 1
            j = i
            while j < n and expression[j].isdigit():
                j += 1
            numerator = sign * int(expression[i:j])
            i = j + 1
            j = i
            while j < n and expression[j].isdigit():
                j += 1
            denominator = int(expression[i:j])
            result += Fraction(numerator, denominator)           
            i = j       
        return str(result.numerator) + "/" + str(result.denominator)
