#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePermutations(vector<int>& sequence, int start, int end) {
    if (start == end) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        for (int i = start; i <= end; i++) {
            swap(sequence[start], sequence[i]);
            generatePermutations(sequence, start + 1, end);
            swap(sequence[start], sequence[i]);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> sequence(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    generatePermutations(sequence, 0, n - 1);

    return 0;
}
