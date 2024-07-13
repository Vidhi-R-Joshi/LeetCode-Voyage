class Solution(object):
    def survivedRobotsHealths(self, positions, healths, directions):
        robots = list(zip(positions, healths, directions, range(len(positions))))
        robots.sort()
    
        stack = []
    
        for pos, health, direction, original_index in robots:
            if direction == 'R':
                stack.append((health, direction, original_index))
            else:
                while stack and stack[-1][1] == 'R':
                    right_health, right_direction, right_index = stack[-1]
                    if right_health == health:
                        stack.pop()
                        break
                    elif right_health > health:
                        stack[-1] = (right_health - 1, right_direction, right_index)
                        break
                    else:
                        health -= 1
                        stack.pop()
                else:
                    stack.append((health, direction, original_index))
    
        surviving_healths = [0] * len(positions)
        for health, direction, original_index in stack:
            surviving_healths[original_index] = health
    
        return [health for health in surviving_healths if health > 0]
