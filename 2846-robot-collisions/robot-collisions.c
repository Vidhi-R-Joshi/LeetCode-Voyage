// 2751. Robot Collisions
typedef struct Robot {
    int index;
    int position;
    int health;
    char direction;
} robot_t;

int ascend_by_pos(const void* pa, const void* pb) {
    const robot_t a = *(const robot_t*)pa;
    const robot_t b = *(const robot_t*)pb;
    if (a.position == b.position)
        return 0;
    return (a.position < b.position) ? -1 : 1;
}
int ascend_by_index(const void* pa, const void* pb) {
    const robot_t a = *(const robot_t*)pa;
    const robot_t b = *(const robot_t*)pb;
    if (a.index == b.index)
        return 0;
    return (a.index < b.index) ? -1 : 1;
}
int* survivedRobotsHealths(int* positions, int positionsSize, int* healths,
                           int healthsSize, char* directions, int* returnSize) {
    // Simulation + Stack + Sorting

    // Time complexity: O(nlog(n))
    // Space complexity: O(n)

    const int n = positionsSize;
    robot_t robots[n];
    for (int i = 0; i < n; i++) {
        robots[i] = (robot_t){.index = i,
                              .position = positions[i],
                              .health = healths[i],
                              .direction = directions[i]};
    }

    qsort(robots, n, sizeof(robot_t), ascend_by_pos);

    robot_t stack[n]; // the runnnig robots
    int top = -1;
    for (int i = 0; i < n; i++) {
        if (robots[i].direction == 'R') {
            stack[++top] = robots[i];
            continue;
        }
        // collide with robots going right if any
        while (top != -1 && stack[top].direction == 'R' &&
               robots[i].health > 0) {
            if (stack[top].health == robots[i].health) {
                top--;
                robots[i].health = 0;
            } 
            else if (stack[top].health < robots[i].health) {
                top--;
                robots[i].health -= 1;
            } 
            else { // stack[top].health > robots[i].health
                stack[top].health -= 1;
                robots[i].health = 0;
            }
        }
        if (robots[i].health > 0) {
            stack[++top] = robots[i];
        }
    }

    const int size = top + 1;
    qsort(stack, size, sizeof(robot_t), ascend_by_index);

    int* result = (int*)calloc(size, sizeof(int));
    *returnSize = size;
    for (int i = 0; i < size; i++) {
        result[i] = stack[i].health;
    }
    return result;
}