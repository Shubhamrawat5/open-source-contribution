//This C++ program checks if a given string of brackets is balanced or not. It uses a stack-based approach to ensure that each opening bracket has a corresponding closing bracket in the correct order.

#include <bits/stdc++.h>
using namespace std;

// Map to associate brackets with their respective values
unordered_map<char, int> bracket = {
    {'(', 1}, {'{', 2}, {'[', 3},
    {')', -1}, {'}', -2}, {']', -3}
};

// Function to check if the brackets in the string are balanced
string isBalanced(string s) {   
    stack<char> st;    // Stack to keep track of opening brackets
    for(char currentChar : s){   // Use a descriptive name for the loop variable
        if(bracket[currentChar] > 0) {
            st.push(currentChar);  // Push opening brackets onto the stack
        } else {
            if(st.empty()) return "NO";  // No matching opening bracket
            char top = st.top();
            st.pop();
            // Check if the brackets match
            if(bracket[top] + bracket[currentChar] != 0) {
                return "NO";  // Mismatched brackets
            }
        }
    }
    return st.empty() ? "YES" : "NO";   // Return YES if all brackets matched
}

int main() {
    int t;
    cin >> t;  // Read number of test cases
    while(t--) {  
        string s;
        cin >> s;  // Read the string of brackets
        cout << isBalanced(s) << endl;  // Output the result
    }
}
