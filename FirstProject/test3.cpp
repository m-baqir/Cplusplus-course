#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	const int luckysnum1 = 1;
	const int luckysnum2 = 6;
	const int luckysnum3 = 8;
	int rand1, rand2, rand3;
	int count = 0;
	srand(time(0));

	while (true) {
		rand1 = rand() % 9 + 1;
		rand2 = rand() % 9 + 1;
		rand3 = rand() % 9 + 1;
		count++;
		cout << "This draw's numbers are " << rand1 << " " << rand2 << " " << rand3;
		if (luckysnum1 == rand1 && luckysnum2 == rand2 && luckysnum3 == rand3) {
			cout << "Mr.Lucky is a grand price winner after " << count << " draws!" << endl;
			break;
		}
		else {
			cout << "Better luck next time!" << endl;
		}
	}
}
