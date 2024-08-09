class Solution(object):
    def numMagicSquaresInside(self, grid):
        def is_magic(square):
            values = [square[i][j] for i in range(3) for j in range(3)]
            if sorted(values) != list(range(1, 10)):
                return False

            expected_sum = sum(square[0])
            for row in square:
                if sum(row) != expected_sum:
                    return False
            for col in range(3):
                if sum(square[row][col] for row in range(3)) != expected_sum:
                    return False
            if sum(square[i][i] for i in range(3)) != expected_sum:
                return False
            if sum(square[i][2-i] for i in range(3)) != expected_sum:
                return False

            return True

        count = 0
        for i in range(len(grid) - 2):
            for j in range(len(grid[0]) - 2):
                square = [row[j:j+3] for row in grid[i:i+3]]
                if is_magic(square):
                    count += 1
        return count
