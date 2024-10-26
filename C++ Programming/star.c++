#include <iostream>
using namespace std;

int main() {
    int rows;

    // Taking the number of rows as input from the user
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Printing the star pattern
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
