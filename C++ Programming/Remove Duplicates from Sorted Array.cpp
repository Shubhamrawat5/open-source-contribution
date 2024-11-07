#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // for INT_MIN

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k, s;
        vector<int> copy;
        copy = nums;
        auto p = unique(nums.begin(), nums.end());
        nums.erase(p, nums.end());
        k = nums.size();
        s = copy.size();
        for (int i = k; i < s; i++) {
            nums.push_back(INT_MIN);
        }
        return k;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4}; // Example array with duplicates

    Solution sol;
    int k = sol.removeDuplicates(nums);
    
    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " "; // Print only unique elements
    }
    cout << endl;

    return 0;
}