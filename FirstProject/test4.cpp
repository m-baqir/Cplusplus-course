#include <iostream>
using namespace std;

class Fluid {
private:
	int gallons;
	int pints;
public:
	Fluid(int g=0, int p=0):gallons(g),pints(p){}
	Fluid& setGallons(int g) {
		if (g >= 0) {
			gallons = g;
		}
		else {
			cout << "Gallons are not greater then or equal to 0" << endl;
			exit(1);
		}
		return *this;
	}
	Fluid& setPints(int p) {
		if (p >= 0 && p < 8) {
			pints = p;
		}
		else {
			cout << "Pints are not greater then 0 and less then 8" << endl;
			exit(1);
		}
		return *this;
	}
	int getGallons()const {
		return gallons;
	}
	int getPints()const {
		return pints;
	}

	friend istream& operator>>(istream& in, Fluid& f) {
		cout << "Enter the gallons: ";
		in >> f.gallons;
		cout << "Enter the pints: ";
		in >> f.pints;
		return in;
	}
	friend ostream& operator<<(ostream& out, Fluid& f) {
		out << f.gallons << "gal" << f.pints << "pnt";
		return out;
	}
	Fluid operator+(const Fluid& other) const {
		int totalGal = gallons + other.gallons;
		int totalPnt = pints + other.pints;
		if (totalPnt >= 8) {
			totalGal = (totalGal + totalPnt) / 8;
			totalPnt %= 8;
		}
		return Fluid(totalGal, totalPnt);
	}
	operator int() const {
		return gallons;
	}
};
int main() {
	Fluid a(5, 6);
	Fluid b(7, 8);
	a.setGallons(2).setPints(3);
	Fluid c = a + b;
	int onlyGal = static_cast<int>(a);
	cout << "Fluid a: " << a << endl;
	cout << "Fluid b: " << b << endl;
	cout << "Fluid c = Fluid a+Fluid b: " << c << endl;
	cout << "Gallons only: " << onlyGal << endl;
}