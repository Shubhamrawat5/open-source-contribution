def countBattleships(board):
    if not board:
        return 0

    rows, cols = len(board), len(board[0])
    count = 0

    for i in range(rows):
        for j in range(cols):
            if board[i][j] == 'X':
                if i > 0 and board[i - 1][j] == 'X':
                    continue
                if j > 0 and board[i][j - 1] == 'X':
                    continue
                count += 1

    return count

board = []
print("Enter the board row by row, use 'X' for battleships and '.' for empty cells. Press Enter after each row. To finish, press Enter with an empty row.")

while True:
    row = input()
    if not row:
        break
    board.append(list(row))

result = countBattleships(board)
print("Number of battleships:", result)
