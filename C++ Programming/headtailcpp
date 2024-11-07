#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Get user's choice
    std::string userChoice;
    std::cout << "Welcome to the Head-Tail Game!\n";
    std::cout << "Enter your choice (Head or Tail): ";
    std::cin >> userChoice;

    // Convert user input to lowercase for easier comparison
    for (auto &c : userChoice) c = tolower(c);

    // Generate a random number: 0 for Head, 1 for Tail
    int coinFlip = rand() % 2;
    std::string result = (coinFlip == 0) ? "head" : "tail";

    // Display the result of the coin toss
    std::cout << "Coin flipped: " << result << "!\n";

    // Check if the user won or lost
    if (userChoice == result) {
        std::cout << "Congratulations! You won!\n";
    } else {
        std::cout << "Sorry! You lost. Better luck next time.\n";
    }

    return 0;
}
