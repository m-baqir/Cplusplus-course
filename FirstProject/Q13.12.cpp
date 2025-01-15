#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << right << setw(14) << "Fahrenheit" << setw(14) << "Celsius" << endl;
	for (int fahrenheit = 0; fahrenheit <= 212; ++fahrenheit) {
		double celsius = 5.0 / 9.0 * (fahrenheit - 32);
		cout << right << setw(14) << fahrenheit << setw(14) << fixed << setprecision(3) << celsius << endl;
	}
}