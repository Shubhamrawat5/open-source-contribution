def is_safe(board, row, col, n):
    # Check if there is a queen in the same column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check upper-left diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check upper-right diagonal
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens(n):
    board = [[0] * n for _ in range(n)]

    def solve(row):
        if row == n:
            return True

        for col in range(n):
            if is_safe(board, row, col, n):
                board[row][col] = 1
                if solve(row + 1):
                    return True
                board[row][col] = 0

        return False

    if solve(0):
        return board
    else:
        return []

# Example usage
n = 8
solution = solve_n_queens(n)
if solution:
    for row in solution:
        print(' '.join(['Q' if cell == 1 else '.' for cell in row]))
else:
    print("No solution found.")
