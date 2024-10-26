#include<iostream>
#include<string>
using namespace std;

class BinaryConverter {
private:
    string binaryNum;
public:
    void setBinaryNum(string num) {
        binaryNum = num;
    }

    int binaryToDecimal() {
        int decimalNum = 0;
        int base = 1;

        for(int i = binaryNum.length() - 1; i >= 0; i--) {
            if(binaryNum[i] == '1') {
                decimalNum += base;
            }
            base *= 2;
        }

        return decimalNum;
    }

    void displayConversion() {
        int decimalNum = binaryToDecimal();
        cout << "The decimal equivalent of " << binaryNum << " is " << decimalNum << endl;
    }

    bool isValidBinary() {
        for(int i = 0; i < binaryNum.length(); i++) {
            if(binaryNum[i] != '0' && binaryNum[i] != '1') {
                return false;
            }
        }
        return true;
    }

    bool isEmpty() {
        return binaryNum.empty();
    }

    bool isTooLong() {
        return binaryNum.length() > 32; // assuming 32-bit integer
    }
};

int main() {
    BinaryConverter converter;
    string binaryNum;
    cout << "Enter a binary number: ";
    cin >> binaryNum;

    converter.setBinaryNum(binaryNum);

    if(converter.isEmpty()) {
        cout << "Error: Binary number cannot be empty." << endl;
    } else if(converter.isTooLong()) {
        cout << "Error: Binary number is too long. Maximum length is 32 bits." << endl;
    } else if(!converter.isValidBinary()) {
        cout << "Error: Invalid binary number. Please enter a number consisting only of 0s and 1s." << endl;
    } else {
        converter.displayConversion();
    }

    return 0;
}