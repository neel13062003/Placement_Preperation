from typing import List

class Solution:
    
    def isValid(self, row, col, board: List[List[str]], c) -> bool:
        for i in range(0, 9):
            if board[row][i] == c:
                return False
            if board[i][col] == c:
                return False
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
                return False
        return True
    
    def solve(self, board: List[List[str]]) -> bool:
        n = len(board)
        m = len(board[0])
        for i in range(n):
            for j in range(m):
                if board[i][j] == '.':
                    for c in range(1, 10):
                        if self.isValid(i, j, board, str(c)):
                            board[i][j] = str(c)
                            if self.solve(board):
                                return True
                            else:
                                board[i][j] = '.'
                    return False    
        return True
                        
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.solve(board)
