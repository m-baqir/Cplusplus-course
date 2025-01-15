#include <iostream>
using namespace std;

int main() {
	int productNum, quantity;
	double totalValue = 0.0,price = 0.0;
	while (true) {
		cout << "Enter Product number (1-5) and the respective quantity sold or enter -1 to end: ";
		cin >> productNum;
		if (productNum == -1) {
			break;
		}
		cin >> quantity;
		switch (productNum) {
		case 1:
			price = 2.89;
			break;
		case 2:
			price = 4.50;
			break;
		case 3:
			price = 9.98;
			break;
		case 4:
			price = 4.49;
			break;
		case 5:
			price = 6.87;
			break;
		default:
			cout << "Invalid product number" << endl;
			continue;
		}
		totalValue += price * quantity;
	}
	cout << "Total value of all products: $" << totalValue << endl;
}