void dfs(int **grid, int gridSize, int x, int y) {
    if (x < 0 || y < 0 || x >= gridSize || y >= gridSize || grid[x][y] != 0) {
        return;
    }
    grid[x][y] = 1;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        dfs(grid, gridSize, newX, newY);
    }
}



int regionsBySlashes(char** grid, int gridSize) {
    int **bigGrid = (int**)calloc(gridSize * 3, sizeof(int*));
    for(int i = 0; i < gridSize * 3; i++) {
        bigGrid[i] = (int*)calloc(gridSize * 3, sizeof(int));
    }

    for(int i= 0;i<gridSize;i++){
        for(int j=0;j<gridSize;j++){
            if(grid[i][j] == '/'){
                bigGrid[i*3][j*3+2] =1;
                bigGrid[i*3+1][j*3+1] =1;
                bigGrid[i*3+2][j*3] =1;
            }else if(grid[i][j] == '\\'){
                bigGrid[i*3][j*3] =1;
                bigGrid[i*3+1][j*3+1] =1;
                bigGrid[i*3+2][j*3+2] =1;
            }
            else{
                continue;
            }
        }
    }
    int count =0;
    for(int i= 0;i<gridSize*3;i++){
        for(int j=0;j<gridSize*3;j++){
            if(bigGrid[i][j]==0){
                dfs(bigGrid,gridSize*3,i,j);
                count++;
            }else{
                continue;
            }
        }
    }
    for (int i = 0; i < gridSize * 3; i++) {
        free(bigGrid[i]);  
    }
    free(bigGrid);  
    return count;
}