#include <iostream>
using namespace std;

int main()
{

    int num;
    cout << "Enter Your Number : " << endl;
    cin >> num;
    int t = num;
    int sum = 0;
    while (num > 0)
    {
        int digit;
        digit = num % 10;
        int fact = 1;
        for (int i = digit; i >= 1; i--)
        {

            fact = fact * i;
        }

        sum = sum + fact;

        num = num / 10;
    }

    if (sum == t)
    {

        cout << "The number is a strong number ";
    }
    else
    {
        cout << "The number is not a strong number ";
    }
    return 0;
}