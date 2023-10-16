#include <iostream>
#include <vector>

using namespace std;

vector<int> flatten2DVector(vector<vector<int>>& input) {
    vector<int> flattened;
    for (const vector<int>& row : input) {
        for (int num : row) {
            flattened.push_back(num);
        }
    }
    return flattened;
}

int main() {
    int numRows, numCols;
    cout << "Enter the number of rows in the 2D vector: ";
    cin >> numRows;
    cout << "Enter the number of columns in the 2D vector: ";
    cin >> numCols;

    vector<vector<int>> twoDVector(numRows, vector<int>(numCols));

    cout << "Enter the elements of the 2D vector:" << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> twoDVector[i][j];
        }
    }

    vector<int> flattenedVector = flatten2DVector(twoDVector);

    cout << "Flattened 1D vector: ";
    for (int num : flattenedVector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
