class Solution(object):
    def numRescueBoats(self, people, limit):
        people.sort()
        l, r = 0, len(people) - 1
        res = 0
        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1
            res += 1
            r -= 1
        return res