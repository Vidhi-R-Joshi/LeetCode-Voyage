class Solution:
    def findMaximizedCapital(self, k, w, pr, cp):
        n = len(pr)
        projects = sorted(zip(cp, pr), key=lambda x: x[0])
        
        min_heap = []
        i = 0
        while k > 0:
            while i < n and w >= projects[i][0]:
                heapq.heappush(min_heap, -projects[i][1])
                i += 1
            if min_heap:
                w += -heapq.heappop(min_heap)
            k -= 1
        
        return w
