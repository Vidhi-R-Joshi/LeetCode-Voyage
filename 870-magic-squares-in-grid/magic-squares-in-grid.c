bool print3x3Submatrix(int** grid, int startRow, int startCol) {
    int *arr = (int*)calloc(9, sizeof(int));
    bool seen[10] = {false}; 

    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int value = grid[startRow + i][startCol + j];
            if (value > 0 && value < 10) {
                if (seen[value]) { 
                    free(arr);
                    return false;
                }
                seen[value] = true;
                arr[k++] = value;
            } else {
                free(arr);
                return false;
            }
        }
    }

    int sum = arr[0] + arr[1] + arr[2];
    if (arr[3] + arr[4] + arr[5] != sum ||
        arr[6] + arr[7] + arr[8] != sum ||
        arr[0] + arr[3] + arr[6] != sum ||
        arr[1] + arr[4] + arr[7] != sum ||
        arr[2] + arr[5] + arr[8] != sum ||
        arr[0] + arr[4] + arr[8] != sum ||
        arr[2] + arr[4] + arr[6] != sum) {
        free(arr);
        return false;
    }
    
    free(arr);
    return true;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    if(gridSize<3 || *gridColSize<3)return 0;
    int count= 0;
    for(int i=0; i<=gridSize-3; i++){
        for(int j=0; j<=*gridColSize-3; j++){
            if(print3x3Submatrix(grid,i,j)){
                count++;
            }
            printf("\n\n");
        }
    }
    return count;
}