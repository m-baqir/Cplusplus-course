#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int num = 1 + rand() % 1000;
	int myGuess = 0;
	cout << "I have a number between 1 and 1000." << endl;
	cout << "Can you guess my number?" << endl;
	cout << "Please type your first guess" << endl;

	while (myGuess != num) {
		cin >> myGuess;
		if (myGuess < num) {
			cout << "Too low. Try again." << endl;
		}
		else if (myGuess > num) {
			cout << "Too high. Try again." << endl;
		}
		else {
			cout << "Excellent! You guessed the number!" << endl;
		}
	}
}