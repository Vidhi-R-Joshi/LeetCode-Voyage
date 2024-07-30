class Solution(object):
    def minimumDeletions(self, s):
        n = len(s)
        cnt_a = [0] * (n + 1)
        cnt_b = [0] * (n + 1)
    
        for i in range(1, n + 1):
            cnt_a[i] = cnt_a[i - 1] + (1 if s[i - 1] == 'a' else 0)
            cnt_b[i] = cnt_b[i - 1] + (1 if s[i - 1] == 'b' else 0)
    
        min_dels = float('inf')
    
        for i in range(n + 1):
            dels = cnt_b[i] + (cnt_a[n] - cnt_a[i])
            min_dels = min(min_dels, dels)
    
        return min_dels
