//2sum problem solution in cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // stores the element and its index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // find the complement
        if (map.find(complement) != map.end()) {
            // if the complement is found, return the indices
            return {map[complement], i};
        }
        map[nums[i]] = i; // store the element and its index
    }
    return {}; // return empty if no solution
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found" << endl;
    }

    return 0;
}
