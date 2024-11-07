#include <iostream>
using namespace std;

#define d 256  // Number of characters in the input alphabet
#define q 101  // A prime number for hashing

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // We might get a negative value of t, convert it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "Hello World";
    string pattern = "World";

    rabinKarp(text, pattern);

    return 0;
}
