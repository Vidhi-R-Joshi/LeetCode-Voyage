#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minHeightShelves(int** books, int booksSize,int* booksColSize, int shelfWidth) {
    int* f = (int*)malloc((booksSize + 1) * sizeof(int));
    for (int i = 0; i <= booksSize; i++) {
        f[i] = 0;
    }

    for (int i = 1; i <= booksSize; i++) {
        int w = books[i - 1][0];
        int h = books[i - 1][1];
        f[i] = f[i - 1] + h;

        for (int j = i - 1; j > 0; j--) {
            w += books[j - 1][0];
            if (w > shelfWidth) {
                break;
            }
            h = (h > books[j - 1][1]) ? h : books[j - 1][1];
            f[i] = (f[i] < f[j - 1] + h) ? f[i] : (f[j - 1] + h);
        }
    }
    int result = f[booksSize];
    free(f);
    return result;
}

