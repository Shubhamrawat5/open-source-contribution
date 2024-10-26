#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;

    // // Vector to store factorial results for each step
    // vector<int> factorial(n + 1);

    // // Initial factorial of 0 and 1 is 1
    // factorial[0] = 1;

    // // Calculate factorial using previous results stored in the vector
    // for (int i = 1; i <= n; ++i) {
    //     factorial[i] = factorial[i - 1] * i;
    // }
    // cout << "Factorial of " << n << " is: " << factorial[n] << endl;

    // space optimised approach
    // Approach : - we can observe from the above code logic that it is using
    // previous factorial value and after multiplication with the current number
    // it is getting the factorial of current number, so instead of taking a
    // vector of size n+1 , we are taking a output variable (say 'fact')
    // initializing it with 1 because the factorial of 0 is 1. Then we are
    // taking a while loop and doing it's multiplication with the current number
    // until we reached to our requied number.

    // speical case :- There may be a case where user enter a negative number
    // then we have to tell the user that factorial of negative number is not
    // defined.

    if (n < 0)
        cout << "Factorial of negative number is not defined" << endl;

    // we are taking lon long here because factorial is a multiplication process
    // and it may cause a overflow if we take factorial output as integer
    long long fact = 1;

    // if n is equal to 0 or 1 for both cases the below code will return 1 as i
    // is intially 1 so multiplication of 1 with itself is also 1.
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    cout << "Factorial of " << n << " is: " << fact << endl;

    return 0;
}
