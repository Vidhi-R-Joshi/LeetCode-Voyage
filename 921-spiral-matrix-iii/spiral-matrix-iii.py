class Solution(object):
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        res = [[rStart, cStart]]
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        steps = 1
        r, c = rStart, cStart
        i = 0
        while len(res) != rows * cols:
            for w in range(2):
                dr, dc = dirs[i][0], dirs[i][1]
                for q in range(steps):
                    r, c = r + dr, c + dc
                    if (0 <= r <rows) and (0 <= c < cols):
                        res.append([r, c])
                i = (i + 1) % 4    
            steps += 1
        return res