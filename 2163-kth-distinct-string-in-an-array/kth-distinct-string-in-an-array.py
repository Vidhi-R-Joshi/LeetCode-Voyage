class Solution:
    def kthDistinct(self, arr, k):
        x = Counter(arr)
      
        for i in arr:
            if x[i] == 1:
                k -= 1
                if k == 0:
                    return i
      
        return ''
