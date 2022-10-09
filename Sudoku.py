class Solution:
    def solveSudoku(self, board) -> None:
        def rowcol(row, col, board):
            big = set(["1", "2", "3", "4", "5", "6", "7", "8", "9"])
            temp = set(board[row])

            column = []
            for rows in board:
                column.append(rows[col])

            temp2 = set(column)

            row = int(row / 3) * 3
            col = int(col / 3) * 3
            temp3 = []
            for rows in range(row, row + 3):
                for cols in range(col, col + 3):
                    temp3.append(board[rows][cols])
            mat = set(temp3)
            mset = big.difference(temp3, temp, temp2)
            return mset

        def solve(board):
            for rows in range(9):
                for cols in range(9):
                    if board[rows][cols] == ".":
                        op = rowcol(rows, cols, board)
                        if op:
                            for item in op:
                                board[rows][cols] = item
                                val = solve(board)
                                if val == False:
                                    board[rows][cols] = "."
                                else:
                                    return True
                            return False
                        else:
                            return False
            return True

        solve(board)
        return
