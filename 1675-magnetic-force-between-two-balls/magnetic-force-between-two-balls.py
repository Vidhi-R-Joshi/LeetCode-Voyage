class Solution:
    def getK(self, arr, x, m):
        last = 0
        m -= 1
        for i in range(len(arr)):
            if arr[i] - arr[last] >= x:
                m -= 1
                last = i
            if m == 0:
                return True
        return False

    def maxDistance(self, arr, m):
        arr.sort()
        i, ans = 0, 0
        j = arr[-1]
        while i <= j:
            mid = i + (j - i) // 2
            if self.getK(arr, mid, m):
                i = mid + 1
                ans = mid
            else:
                j = mid - 1
        return ans

