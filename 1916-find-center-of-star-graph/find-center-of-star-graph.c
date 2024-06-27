#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u;
    int v;
} Edge;

int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;
    int* degree = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        degree[u]++;
        degree[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] == n - 1) {
            free(degree);
            return i;
        }
    }

    free(degree);
    return -1;
}