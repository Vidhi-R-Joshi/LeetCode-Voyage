class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        x, y = len(arr1), len(arr2)
        a = 0

        for i in range(y):
            for j in range(x):
                if arr1[j] == arr2[i]:
                    arr1[a], arr1[j] = arr1[j], arr1[a]
                    a += 1

        arr1[a:] = sorted(arr1[a:])

        return arr1
