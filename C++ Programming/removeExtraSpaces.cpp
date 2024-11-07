#include <iostream>
#include <string>
#include <cctype>

std::string removeExtraSpaces(const std::string& str) {
    std::string result;
    bool inSpace = false;

    for (char ch : str) {
        if (std::isspace(ch)) {
            if (!inSpace) { // Only add one space
                result += ' ';
                inSpace = true;
            }
        } else {
            result += ch; // Add the non-space character
            inSpace = false;
        }
    }

    // Trim leading and trailing spaces
    if (!result.empty() && result.front() == ' ') {
        result.erase(result.begin()); // Remove leading space
    }
    if (!result.empty() && result.back() == ' ') {
        result.pop_back(); // Remove trailing space
    }

    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::string output = removeExtraSpaces(input);
    std::cout << "Sentence after removing extra spaces: '" << output << "'" << std::endl;

    return 0;
}
