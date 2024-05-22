class Solution(object):
    def partition(self, s):
        def palindrome(s):
            return s == s[::-1]
    
        def backtracking(s, path, res):
            if not s:
                res.append(path)
                return
        
            for i in range(1, len(s) + 1):
                if palindrome(s[:i]):
                    backtracking(s[i:], path + [s[:i]], res)
    
        res = []
        backtracking(s, [], res)
        return res
