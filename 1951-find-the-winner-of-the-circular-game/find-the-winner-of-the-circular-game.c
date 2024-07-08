#include <stdio.h>
#include <stdlib.h>

int findTheWinner(int n, int k) {
    int *x = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        x[i] = i + 1;
    }
    int index = 0;

    while (n > 1) {
        index = (index + k - 1) % n;
        for (int i = index; i < n - 1; i++) {
            x[i] = x[i + 1];
        }
        n--;
    }

    int winner = x[0];
    free(x);
    return winner;
}

