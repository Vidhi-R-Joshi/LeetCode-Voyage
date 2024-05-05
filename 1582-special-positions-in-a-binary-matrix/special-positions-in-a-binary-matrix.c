int numSpecial(int** mat, int matSize, int* matColSize) {
    int cnt = 0;
    
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < *matColSize; j++) {
            if (mat[i][j] == 1) {
                bool rowHasOther = false;
                bool colHasOther = false;
                
                for (int k = 0; k < *matColSize; k++) {
                    if (k != j && mat[i][k] == 1) {
                        rowHasOther = true;
                        break;
                    }
                }
                
                for (int k = 0; k < matSize; k++) {
                    if (k != i && mat[k][j] == 1) {
                        colHasOther = true;
                        break;
                    }
                }
                
                if (!rowHasOther && !colHasOther) {
                    cnt++;
                } else {
                    break;
                }
            }
        }
    }
    
    return cnt;
}
