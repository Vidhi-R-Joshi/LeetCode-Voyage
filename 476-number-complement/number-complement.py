class Solution:
    def findComplement(self, num):
        binary_str = bin(num)[2:]
        res = ''
        for char in binary_str:
            if char == '0':
                res += '1'
            else:
                res += '0'
        return int(res, 2)
