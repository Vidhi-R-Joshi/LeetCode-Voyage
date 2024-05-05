class Solution(object):
    def numSpecial(self, mat):
        rows, cols = len(mat), len(mat[0])
        cnt = 0

        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 1:
                    if any(mat[i][k] == 1 for k in range(cols) if k != j):
                        break
                    else:
                        if any(mat[k][j] == 1 for k in range(rows) if k != i):
                            break
                        else:
                            cnt += 1
        
        return cnt
