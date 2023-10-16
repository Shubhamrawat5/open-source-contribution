#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

void initializeGrid(vector<vector<char>>& grid, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        vector<char> row;
        for (int j = 0; j < cols; j++) {
            char cell = (rand() % 2 == 0) ? 'O' : ' ';
            row.push_back(cell);
        }
        grid.push_back(row);
    }
}

void printGrid(const vector<vector<char>>& grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int countNeighbors(const vector<vector<char>>& grid, int row, int col, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighborRow = row + i;
            int neighborCol = col + j;
            if (i == 0 && j == 0) continue;
            if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
                if (grid[neighborRow][neighborCol] == 'O') {
                    count++;
                }
            }
        }
    }
    return count;
}

void evolveGrid(vector<vector<char>>& grid, int rows, int cols) {
    vector<vector<char>> newGrid = grid;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(grid, i, j, rows, cols);
            if (grid[i][j] == 'O') {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = ' ';
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 'O';
                }
            }
        }
    }
    grid = newGrid;
}

int main() {
    int numRows, numCols, generations;
    cout << "Enter the number of rows in the grid: ";
    cin >> numRows;
    cout << "Enter the number of columns in the grid: ";
    cin >> numCols;
    cout << "Enter the number of generations: ";
    cin >> generations;

    vector<vector<char>> grid;
    initializeGrid(grid, numRows, numCols);

    for (int generation = 0; generation < generations; generation++) {
        system("clear");
        printGrid(grid, numRows, numCols);
        evolveGrid(grid, numRows, numCols);
        usleep(100000);
    }

    return 0;
}
