#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum value in the array
    int maxVal = *max_element(arr.begin(), arr.end());

    // Create a count array to store the count of each unique value
    vector<int> count(maxVal + 1, 0);

    // Count each element in the original array
    for (int num : arr) {
        count[num]++;
    }

    // Modify the count array to store the cumulative count
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Create a sorted output array
    vector<int> output(arr.size());

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    arr = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    countingSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
