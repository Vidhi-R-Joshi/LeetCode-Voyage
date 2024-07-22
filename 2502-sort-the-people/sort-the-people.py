class Solution:
    def sortPeople(self, names, heights):
        n = len(heights)
        arr = [[heights[i], i] for i in range(n)]
        arr.sort(key=lambda x: x[0], reverse=True)
        ans = [names[arr[i][1]] for i in range(n)]
        return ans
