#include <iostream>
using namespace std;

int countWaysToPaintFence(int posts, int colors) {
    if (posts == 0 || colors == 0) return 0;
    if (posts == 1) return colors;
    
    int sameColorCount = colors;
    int diffColorCount = colors * (colors - 1);
    
    for (int i = 3; i <= posts; i++) {
        int total = (sameColorCount + diffColorCount) * (colors - 1);
        sameColorCount = diffColorCount;
        diffColorCount = total;
    }
    
    return sameColorCount + diffColorCount;
}

int main() {
    int posts, colors;
    cout << "Enter the number of posts: ";
    cin >> posts;
    cout << "Enter the number of colors: ";
    cin >> colors;
    
    int ways = countWaysToPaintFence(posts, colors);
    cout << "Number of ways to paint the fence: " << ways << endl;
    
    return 0;
}
