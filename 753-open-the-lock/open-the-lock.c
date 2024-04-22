#include <stdlib.h>
#include <stdbool.h>

bool isOpen(char* lock) {
    for (int i = 0; i < 4; i++) {
        if (lock[i] != '0') {
            return false;
        }
    }
    return true;
}

void getNeighbors(char* lock, char** neighbors) {
    for (int i = 0; i < 4; i++) {
        neighbors[i] = (char*)malloc(5 * sizeof(char));
        strcpy(neighbors[i], lock);
        neighbors[i][i] = (neighbors[i][i] - '0' + 1) % 10 + '0';
        
        neighbors[i + 4] = (char*)malloc(5 * sizeof(char));
        strcpy(neighbors[i + 4], lock);
        neighbors[i + 4][i] = (neighbors[i + 4][i] - '0' + 9) % 10 + '0';
    }
}

int openLock(char **deadends, int deadendsSize, char *target) {
    char *start = "0000";
    if (strcmp(start, target) == 0) return 0;
    
    bool *visited = (bool*)malloc(10000 * sizeof(bool));
    memset(visited, false, 10000 * sizeof(bool));
    for (int i = 0; i < deadendsSize; i++) {
        int idx = atoi(deadends[i]);
        visited[idx] = true;
    }
    
    if (visited[0]) return -1;
    
    int level = 0;
    char **q = (char**)malloc(10000 * sizeof(char*));
    int front = 0, rear = 0;
    q[rear++] = start;
    visited[0] = true;
    
    while (front != rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            char *curr = q[front++];
            if (strcmp(curr, target) == 0) return level;
            
            char **neighbors = (char**)malloc(8 * sizeof(char*));
            getNeighbors(curr, neighbors);
            
            for (int j = 0; j < 8; j++) {
                int idx = atoi(neighbors[j]);
                if (!visited[idx]) {
                    visited[idx] = true;
                    q[rear++] = neighbors[j];
                }
            }
        }
        level++;
    }
    
    return -1;
}
