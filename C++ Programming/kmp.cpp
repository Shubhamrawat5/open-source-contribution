#include <iostream>
#include <vector>
using namespace std;

// Function to preprocess the pattern and create the LPS array
void computeLPSArray(string pattern, int m, vector<int>& lps) {
    int length = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;      // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                // Fall back to the previous position in LPS array
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to implement KMP pattern matching algorithm
void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    // Create the LPS array to hold the longest prefix suffix values
    vector<int> lps(m);

    // Preprocess the pattern
    computeLPSArray(pattern, m, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // Move to the next position in the pattern using LPS
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];  // Move to the next viable position in the pattern
            } else {
                i++;
            }
        }
    }
}

// Main function to test the KMP algorithm
int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    KMPSearch(text, pattern);

    return 0;
}
