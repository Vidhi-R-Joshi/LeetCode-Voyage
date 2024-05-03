class Solution(object):
    def compareVersion(self, version1, version2):
        x = version1.split('.')
        y = version2.split('.')
        ml = min(len(x), len(y))
        for i in range(ml):
            v1 = int(x[i])
            v2 = int(y[i])
            if v1 < v2:
                return -1
            elif v1 > v2:
                return 1
        vers = x if len(x) - ml > 0 else y
        v = 1 if len(x) - ml > 0 else 2
        for i in range(ml, len(vers)):
            if int(vers[i]) > 0:
                return 1 if v == 1 else -1 
        return 0