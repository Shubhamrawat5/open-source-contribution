#include <iostream>
using namespace std;

int main() {
    int num = 42;  
    int guess;
    int numberOfGuesses = 0;

    cout << "Welcome to Guessing Game!" << endl;
    cout << "Guess the number between 1 and 100." << endl;

    // Loop until the user guesses the correct number
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        numberOfGuesses++;

        // Check if the guess is correct, too high, or too low
        if (guess > num) {
            cout << " It's a high number! Try again." << endl;
        } else if (guess < num) {
            cout << "It's a small number! Try again." << endl;
        } else {
            cout << "Hurrrahhh! You've guessed the correct number in " << numberOfGuesses << " attempts." << endl;
        }
    } while (guess != num);

    return 0;
}
