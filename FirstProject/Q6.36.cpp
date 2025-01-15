#include <iostream>
using namespace std;

int power(int base, int exponent) {
	if (exponent == 1) {
		return base;
	}

	return base * power(base, exponent - 1);
}

int main() {
	int base=0, exponent=0;
	cout << "Enter base and exponent:";
	cin >> base >> exponent;
	cout << "power(" << base << ", " << exponent << ") = " << power(base, exponent) << endl;
}