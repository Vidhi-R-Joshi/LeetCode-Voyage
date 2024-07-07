class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        x = numBottles
        y = numBottles

        while y >= numExchange:
            z = y // numExchange
            x += z
            y = z + (y % numExchange)
        
        return x
