#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int), cmpfunc);
    int l = 0, r = peopleSize - 1;
    int res = 0;
    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l++;
        }
        res++;
        r--;
    }
    return res;
}