#include <iostream>
#include <cmath>

int main() {
    double base, exponent;
    std::cout << "Enter base : ";
    std::cin >> base ;
    std::cout << "Enter power : ";
    std::cin >> exponent ;
    double result = pow(base, exponent);
    std::cout << base << " to the power of " << exponent << " = " << result << std::endl;
    return 0;
}
