class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        jobs = sorted(zip(difficulty, profit))
        worker.sort()
        x = 0
        y = 0
        j = 0

        for i in worker:
            while j < len(jobs) and jobs[j][0] <= i:
                y = max(y, jobs[j][1])
                j += 1
            x += y
        
        return x
