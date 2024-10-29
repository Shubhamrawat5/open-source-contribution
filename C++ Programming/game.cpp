#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void showChoice(int choice) {
    switch (choice) {
        case 1: cout << "Rock"; break;
        case 2: cout << "Paper"; break;
        case 3: cout << "Scissors"; break;
    }
}

int getComputerChoice() {
    srand(time(0)); // Seed for random number generation
    return (rand() % 3) + 1; // Random number between 1 and 3
}

int getUserChoice() {
    int choice;
    cout << "Choose:\n1. Rock\n2. Paper\n3. Scissors\n";
    cin >> choice;
    
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice! Please choose 1, 2, or 3: ";
        cin >> choice;
    }
    
    return choice;
}

void determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a draw!\n";
    }
    else if ((userChoice == 1 && computerChoice == 3) || 
             (userChoice == 2 && computerChoice == 1) ||
             (userChoice == 3 && computerChoice == 2)) {
        cout << "You win!\n";
    } 
    else {
        cout << "Computer wins!\n";
    }
}

int main() {
    int userChoice = getUserChoice();
    int computerChoice = getComputerChoice();
    
    cout << "You chose: ";
    showChoice(userChoice);
    cout << "\nComputer chose: ";
    showChoice(computerChoice);
    cout << "\n";
    
    determineWinner(userChoice, computerChoice);
    
    return 0;
}
