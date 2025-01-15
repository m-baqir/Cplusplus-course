#include <iostream>
using namespace std;

int main() {
	double gross, earnings, base= 200.00, comission=0.09;
	while (true) {
		cout << "Enter sales in dollars (-1 to end): ";
			cin >> gross;
		if (gross == -1) {
			break;
		}
		earnings = base + (comission * gross);
		cout << "Salary is: $" << earnings << endl;
	}

}