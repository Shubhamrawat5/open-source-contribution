#include <iostream>
#include <math.h>
using namespace std;
long long int decimal(long long int binValue) {
  long long int counter = 0;
  long long int decValue = 0;
  while (binValue > 0) {
    long long int digit = binValue % 10;
    decValue += (digit*pow(2, counter));
    binValue = binValue/10;
    counter++;
  }
  return decValue;
}

int main() {
  long long int value;
  long long int num;
  cout << "Enter a binary number : ";
  cin >> num;
  if (num != 0) {
    value = decimal(num);
    cout << "Decimal Value is " << value;
  }
  else {
    value = 0;
    cout << "Invalid Inputs..!! ";
  }

  return 0;
}
