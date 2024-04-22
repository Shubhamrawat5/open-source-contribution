#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, 2, 1, 7, 14};
    static int counter[10];
    int num[100];
    int max = arr[0];

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = 1; max / i != 0; i = i * 10)
    {
        for (int j = 0; j < 5; j++)
        {
            ++counter[(arr[j] / i) % 10];
        }
        for (int j = 1; j < 10; j++)
        {
            counter[j] = counter[j - 1] + counter[j];
        }
        for (int j = 4; j >= 0; j--)
        {
            num[--counter[(arr[j] / i) % 10]] = arr[j];
        }
        for (int j = 0; j < 10; j++)
        {
            counter[j] = 0;
        }
        for (int j = 0; j < 5; j++)
        {
            arr[j] = num[j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
