#include <iostream>
#include <limits>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 100);
    const int secret = distribution(generator);
    int guess = 0, attempts = 0;
    cout << "Guess the Number\nCreated by Govind Kumar Vijay\nI have selected a number from 1 to 100.\n";
    while (guess != secret) {
        cout << "Your guess: ";
        if (!(cin >> guess)) { cerr << "Please enter a whole number.\n"; return 1; }
        if (guess < 1 || guess > 100) { cout << "Choose a number from 1 to 100.\n"; continue; }
        ++attempts;
        if (guess < secret) cout << "Too low. Try again.\n";
        else if (guess > secret) cout << "Too high. Try again.\n";
    }
    cout << "Correct! You guessed the number in " << attempts << " attempt(s).\n";
}
