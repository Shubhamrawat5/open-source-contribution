class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize result array with -1
        stack<int> st;  // Stack to store indices of nums

        // Traverse the array twice to handle circular nature
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i % n]) 
            {
                result[st.top()] = nums[i % n];
                st.pop();  // Pop the index once we've found the next greater element
            }
            // Push the index onto the stack during the first traversal
            if (i < n) 
            {
                st.push(i);
            }
        }
        return result;
    }
};
