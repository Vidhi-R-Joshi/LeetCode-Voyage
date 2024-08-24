class Solution(object):
    def nearestPalindromic(self, n):
        length = len(n)
        num = int(n)
    
        if num <= 10:
            return str(num - 1)
        if n == "11":
            return "9"
        if all(c == '9' for c in n):
            return str(num + 2)
    
        def create_palindrome(s, odd_length):
            return int(s + s[-2::-1] if odd_length else s + s[::-1])
    
        half = n[:(length + 1) // 2]
        half_int = int(half)
    
        candidates = set()
        candidates.add(create_palindrome(str(half_int), length % 2 != 0))
        candidates.add(create_palindrome(str(half_int - 1), length % 2 != 0))
        candidates.add(create_palindrome(str(half_int + 1), length % 2 != 0))
        candidates.add(10**(length - 1) - 1)
        candidates.add(10**length + 1)
        candidates.discard(num)
    
        closest_palindrome = None
        min_diff = float('inf')
    
        for candidate in candidates:
            diff = abs(candidate - num)
            if diff < min_diff or (diff == min_diff and candidate < closest_palindrome):
                min_diff = diff
                closest_palindrome = candidate
    
        return str(closest_palindrome)
