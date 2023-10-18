#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    if (envelopes.empty()) return 0;

    sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    vector<int> dp(envelopes.size(), 1);
    int maxCount = 1;

    for (int i = 1; i < envelopes.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i].second > envelopes[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxCount = max(maxCount, dp[i]);
    }

    return maxCount;
}

int main() {
    int n;
    cout << "Enter the number of envelopes: ";
    cin >> n;
    
    vector<pair<int, int>> envelopes;
    
    cout << "Enter the width and height of each envelope:" << endl;
    for (int i = 0; i < n; i++) {
        int width, height;
        cin >> width >> height;
        envelopes.push_back({width, height});
    }

    int maxDolls = maxEnvelopes(envelopes);

    cout << "Maximum number of Russian dolls that can fit: " << maxDolls << endl;

    return 0;
}
