#include <stdio.h>

void diagonalTraverse(int matrix[][10], int m, int n) {
    int row, col;
    for (int i = 0; i < m + n - 1; i++) {
        if (i % 2 == 0) {
            row = (i < m) ? i : m - 1;
            col = (i < m) ? 0 : i - m + 1;
            while (row >= 0 && col < n) {
                printf("%d ", matrix[row][col]);
                row--;
                col++;
            }
        } else {
            col = (i < n) ? i : n - 1;
            row = (i < n) ? 0 : i - n + 1;
            while (col >= 0 && row < m) {
                printf("%d ", matrix[row][col]);
                col--;
                row++;
            }
        }
    }
}

int main() {
    int m, n;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int matrix[10][10];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Diagonal Traverse: ");
    diagonalTraverse(matrix, m, n);
    printf("\n");

    return 0;
}
