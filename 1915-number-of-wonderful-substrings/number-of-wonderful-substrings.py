class Solution:
    def wonderfulSubstrings(self, word):
        n = len(word)
        state = 0
        count = defaultdict(int)
        count[0] = 1
        
        ret = 0
        for i in range(n):
            j = ord(word[i]) - ord('a')
            state ^= (1 << j)
            
            ret += count[state]
            
            for k in range(10):
                ret += count[state ^ (1 << k)]
            
            count[state] += 1
        
        return ret

