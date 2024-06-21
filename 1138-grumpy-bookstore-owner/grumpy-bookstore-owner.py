class Solution(object):
    def maxSatisfied(self, customers, grumpy, minutes):
        x = sum([customers[i] for i in range(len(customers)) if grumpy[i] == 0])
        y = 0
        z = 0

        for i in range(len(customers)):
            z += customers[i] if grumpy[i] == 1 else 0
            if i >= minutes:
                z -= customers[i - minutes] if grumpy[i - minutes] == 1 else 0
            y = max(y, z)
        
        return x + y
