class KthLargest:

    def __init__(self, k, nums):
        self.hq = list(nums)
        self.k = k
        heapify(self.hq)

    def add(self, val):
        heappush(self.hq, val)
        while len(self.hq) > self.k: heappop(self.hq)
        return self.hq[0]
