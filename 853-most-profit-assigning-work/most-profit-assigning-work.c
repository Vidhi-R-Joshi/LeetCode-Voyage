#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int difficulty;
    int profit;
} Job;

int cmpfunc (const void * a, const void * b) {
   return ( ((Job*)a)->difficulty - ((Job*)b)->difficulty );
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    Job* jobs = (Job*)malloc(difficultySize * sizeof(Job));
    for (int i = 0; i < difficultySize; i++) {
        jobs[i].difficulty = difficulty[i];
        jobs[i].profit = profit[i];
    }
    qsort(jobs, difficultySize, sizeof(Job), cmpfunc);
    
    qsort(worker, workerSize, sizeof(int), cmpfunc);
    
    int x = 0;
    int y = 0;
    int j = 0;
    
    for (int i = 0; i < workerSize; i++) {
        while (j < difficultySize && jobs[j].difficulty <= worker[i]) {
            y = (jobs[j].profit > y) ? jobs[j].profit : y;
            j++;
        }
        x += y;
    }
    
    free(jobs);
    return x;
}

