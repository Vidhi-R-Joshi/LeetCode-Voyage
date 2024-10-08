#define MAX_STONE_LENGTH 1000

void dfs(int **stones, int stonesSize, int idx, bool *visited){
    visited[idx]=true;
    for(int i=0; i<stonesSize; i++){
        if((!visited[i]) &&
        ((stones[i][0]==stones[idx][0]) || (stones[i][1]==stones[idx][1])))
        dfs(stones, stonesSize, i, visited);
    }
}


int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    int ret=0;
    bool visited[MAX_STONE_LENGTH]={0};

    for(int i=0; i<stonesSize; i++){
        if(visited[i])
        continue;
        dfs(stones, stonesSize, i, visited);
        ret++;
    }
    return stonesSize-ret;
}