#include <iostream>
#include <sstream>
using namespace std;

class Item {
private:
	double cost;
	static int number;
public:
	Item(double c = 1.0) {
		if (c >= 1.0) {
			cost = c;
		}
		else {
			cost = 1.0;
		}
		number++;
	}
	~Item() {
		number--;
		cout << "An item has been destroyed" << endl;
	}

	void setCost(double c) {
		if (c >= 1.0) {
			cost = c;
		}
	}
	double getCost()const {
		return cost;
	}
	static int getNumber() {
		return number;
	}
	string toString()const {
		ostringstream out;
		out << "$" << cost;
		return out.str();
	}
};

int Item::number = 0;
int main() {
	Item i1;
	Item i2(16.60);
	Item i3(12.25);
	cout << "Number of Items: " << Item::getNumber()<<endl;
	cout << "Item 1: " << i1.toString() << endl;
	cout << "Item 2: " << i2.toString() << endl;
	cout << "Item 3: " << i3.toString() << endl;

	i1.setCost(9.45);
	cout << "Item 1 after setting cost: " << i1.toString() << endl;
	cout << "number of items after changes: " << Item::getNumber() << endl;
}