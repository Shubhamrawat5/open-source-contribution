#include <iostream>
#include <vector>
using namespace std;

#define NO_OF_CHARS 256

// Preprocessing function for Boyer-Moore bad character heuristic
void badCharHeuristic(string pattern, int size, vector<int>& badChar) {
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;

    for (int i = 0; i < size; i++)
        badChar[(int)pattern[i]] = i;
}

void boyerMooreSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> badChar(NO_OF_CHARS);

    // Fill the bad character array by calling the preprocessing function
    badCharHeuristic(pattern, m, badChar);

    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;

        // Keep reducing j while characters of pattern and text are matching
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";

    boyerMooreSearch(text, pattern);

    return 0;
}
