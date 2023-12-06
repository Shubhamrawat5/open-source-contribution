#include <iostream>
using namespace std;
void halfDiamondStar(int N)
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < i + 1; j++)
            cout << "*";
        cout << "\n";
    }
    for (i = 1; i < N; i++) {
        for (j = i; j < N; j++)
            cout << "*";
        cout << "\n";
    }
}
  
int main()
{
    int N = 5;
    halfDiamondStar(N);
}
