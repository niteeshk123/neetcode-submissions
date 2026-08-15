class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = {i:[] for i in range(9)}
        col = {i:[] for i in range(9)}
        sqr = {i:[] for i in range(9)}
        
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    continue
                if board[i][j] in row[i] or board[i][j] in col[j] or board[i][j] in sqr[((i//3)*3) + (j//3)]:
                    return False
                row[i].append(board[i][j])
                col[j].append(board[i][j])
                sqr[((i//3)*3)+(j//3)].append(board[i][j])
        return True
                