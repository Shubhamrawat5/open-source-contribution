#include <iostream>
#include <unordered_map>

using namespace std;

bool isStrobogrammatic(string num) {
    unordered_map<char, char> strobogrammatic = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
    
    int left = 0;
    int right = num.length() - 1;
    
    while (left <= right) {
        if (strobogrammatic.find(num[left]) == strobogrammatic.end() || strobogrammatic[num[left]] != num[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

int main() {
    string num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (isStrobogrammatic(num)) {
        cout << num << " is a strobogrammatic number." << endl;
    } else {
        cout << num << " is not a strobogrammatic number." << endl;
    }
    
    return 0;
}
