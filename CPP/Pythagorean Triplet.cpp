#include <iostream>
#include <math.h>

bool isPythagorean(int n1, int n2, int n3) {
  if ( pow(n1,2) == pow(n2,2)+pow(n3,2) || pow(n2,2) == pow(n3,2)+pow(n1,2) || pow(n3,2) == pow(n1,2)+pow(n2,2)) {
    return true;
  }
  return false;
}

int main() {
  int num1, num2, num3;
  std::cout << "Enter 3 numbers : ";
  std::cin >> num1 >> num2 >> num3;

  if (isPythagorean(num1,num2,num3)) {
    std::cout << "The given triplet is a pythagorean triplet";
  }
  else {
    std::cout << "The given triplet is not a pythagorean triplet";
  }
}
