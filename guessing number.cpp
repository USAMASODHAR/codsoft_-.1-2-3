#include<iostream>
#include <ctime>
#include <cstdlib>  // Using this library to generate random numbers

using namespace std;

int main() {
    // Seeding the random number generator
    srand(time(0));
    
    // Generating a random number between 1 and 100
    int Number = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "************NUMBER GUESSING GAME************\n";
    cout << "Can you can the number between 1 to 100!!.\n";

    do {
        // Getting the player's guess
        cout << "Enter your guess: ";
        cin >> guess;

        // Incrementing the number of attempts
        attempts++;

        // Providing hints
        if (guess > Number) {
            cout << "NO! You are going higher, Try again.\n";
        } else if (guess < Number) {
            cout << "NO! You are going lower, Try again.\n";
        } else {
            cout << "YUP, Here you go! You guessed the number in " << attempts << " attempts.\n";
        }

    } while (guess != Number);

return 0;
}