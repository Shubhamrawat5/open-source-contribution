#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generatePascalsTriangle(int n) {
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}

int main() {
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    vector<vector<int>> pascalsTriangle = generatePascalsTriangle(numRows);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            cout << "   ";
        }
        for (int j = 0; j <= i; j++) {
            cout << pascalsTriangle[i][j] << "     ";
        }
        cout << endl;
    }

    return 0;
}
