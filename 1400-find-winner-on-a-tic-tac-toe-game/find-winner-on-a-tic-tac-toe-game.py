class Solution(object):
    def tictactoe(self, moves):
        grid = [[' ']*3 for _ in range(3)]

        def win_check(row, col, player):
            if all(grid[row][c] == player for c in range(3)):
                return True
            if all(grid[r][col] == player for r in range(3)):
                return True
            if row == col and all(grid[i][i] == player for i in range(3)):
                return True
            if row + col == 2 and all(grid[i][2-i] == player for i in range(3)):
                return True
            return False
        
        player = 0
        for row, col in moves:
            grid[row][col] = "XO"[player]
            if win_check(row, col, "XO"[player]):
                return "AB"[player]
            player ^= 1
        
        return "Draw" if all(' ' not in row for row in grid) else "Pending"