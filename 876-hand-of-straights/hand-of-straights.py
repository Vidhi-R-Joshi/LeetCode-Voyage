class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        if len(hand) % groupSize != 0:
            return False
        
        hand.sort()
        x = Counter(hand)

        for i in sorted(x.keys()):
            if x[i] > 0:
                for j in range(1, groupSize):
                    if i + j not in x or x[i + j] < x[i]:
                        return False
                    x[i + j] -= x[i]
                x[i] = 0
        
        return True
