// A03.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int diceRoll(int max);  // function definition
int getValidInteger();// function definition

int main() {
	srand(time(0)); // seed the random number generator
	const unsigned int MAX_ROLL = 6;

	int exitProgram = 0;
	int guess, rollValue;

	cout << "Hello! Let's play a dice game. Let me do the first roll for you.\n" << endl;
	rollValue = diceRoll(MAX_ROLL);
	cout << "In this roll, you got: " << rollValue << "\n" << endl;

	do {
		rollValue = diceRoll(MAX_ROLL);

		cout << "What's your guess for the next roll? Enter an integer between 1 and " << MAX_ROLL << ": ";
		guess = getValidInteger();
		
		cout << "In this roll, you got: " << rollValue << "\n" << endl;
		cout << endl;

		if (rollValue < guess && guess <= MAX_ROLL) {
			cout << "You guessed too high!";
			cout << endl;
		}
		else if (rollValue > guess && guess >= 0) 
		{
			cout << "You guessed too low!";
			cout << endl;
		}
		else if (rollValue == guess) {
			cout << "You guessed the number!";
			cout << endl;
		}
		else {
			cout << "You guessed a number outside the range!";
			cout << endl;
		}

		cout << "Enter 1 to exit or any other integer to continue rolling ";
		exitProgram = getValidInteger();
		cout << "\n";
		if (exitProgram == 1)
		{
			cout << "Sorry to see you go. Have a wonderful day!\n" << endl;
		}

	} while (exitProgram != 1);

	return 0;
}

// Roll the die
int diceRoll(int max) {
	int rollValue;

	
	rollValue = rand() % max + 1;

	return rollValue;
}


// Check if user entered an integer
int getValidInteger() {
	int userInput;

	cin >> userInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please enter an Integer only ";
		cin >> userInput;
		cout << "\n";
	}

	return userInput;
}