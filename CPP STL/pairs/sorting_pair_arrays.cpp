#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
void sort(int a[], char b[], int n)
{
    pair<int, char> pa[n]; //pair of array [declartion of size n]
    for (int i = 0; i < n; i++)
    {
        pa[i] = {a[i], b[i]};
        /*
        this can we also done by this way
        2nd method:-

        pa[i].first = a[i];
        pa[i].second = b[i];
        */

        /*
         pair will be formed by taking one element from each array
           pa={ (10,'x') ,(15,'y'),(5,'z')}
        */
    }
    sort(pa, pa + n);
    for (int i = 0; i < n; i++)
    {
        cout << pa[i].second << endl;
    }
}
int main()
{
    int a[] = {10, 15, 5};
    char b[] = {'x', 'y', 'z'};
    sort(a, b, 3); // it sorts the value according to first value in the pair....
    // array of pair is by-default sorted by the first element

    return 0;
}
