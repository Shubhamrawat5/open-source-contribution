#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8
#define MINES 10

int grid[ROWS][COLS];

void initializeGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }

    srand(time(NULL));
    int minesPlaced = 0;
    while (minesPlaced < MINES) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (grid[row][col] != -1) {
            grid[row][col] = -1;
            minesPlaced++;
        }
    }
}

void printGrid(int reveal) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (reveal && grid[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int countMines(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }

    if (grid[row][col] == -1) {
        return 1;
    }

    return 0;
}

void uncover(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return;
    }

    if (grid[row][col] == 0) {
        int mineCount = 0;
        for (int r = row - 1; r <= row + 1; r++) {
            for (int c = col - 1; c <= col + 1; c++) {
                mineCount += countMines(r, c);
            }
        }
        grid[row][col] = mineCount;
        if (mineCount == 0) {
            uncover(row - 1, col - 1);
            uncover(row - 1, col);
            uncover(row - 1, col + 1);
            uncover(row, col - 1);
            uncover(row, col + 1);
            uncover(row + 1, col - 1);
            uncover(row + 1, col);
            uncover(row + 1, col + 1);
        }
    }
}

int main() {
    initializeGrid();

    int row, col;
    int revealed = 0;
    int totalCells = ROWS * COLS;

    printf("Minesweeper\n");
    printGrid(0);

    while (revealed < totalCells - MINES) {
        printf("Enter row and column (0-7): ");
        scanf("%d %d", &row, &col);

        if (grid[row][col] == -1) {
            printf("Game Over! You hit a mine.\n");
            printGrid(1);
            break;
        } else {
            if (grid[row][col] == 0) {
                uncover(row, col);
            } else {
                grid[row][col] = grid[row][col];
            }
            revealed++;
            printGrid(0);
        }
    }

    if (revealed == totalCells - MINES) {
        printf("Congratulations! You won!\n");
        printGrid(1);
    }

    return 0;
}
