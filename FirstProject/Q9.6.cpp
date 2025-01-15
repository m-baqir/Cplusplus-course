#include <iostream>
#include<string>
using namespace std;

class Rational {
private:
	int denominator, numerator;

	int gcd(int a, int b) const{
		while (b != 0) {
			int c = b;
			b = a % b;
			a = c;
		}
		return a;
	}

	void reduceFrac() {
		int gcdNum = gcd(abs(numerator), abs(denominator));
		numerator = numerator / gcdNum;
		denominator = denominator / gcdNum;
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}

	}
public:
	Rational(int numer = 2, int denom = 4) :numerator(numer), denominator(denom) {
		reduceFrac();
	}

	Rational add(const Rational& other) const {
		int numer = numerator * other.denominator + other.numerator * denominator;
		int denom = denominator * other.denominator;
		return Rational(numer, denom);
	}

	Rational subtract(const Rational& other) const {
		int numer = numerator * other.denominator - other.numerator * denominator;
		int denom = denominator * other.denominator;
		return Rational(numer, denom);
	}

	Rational multiply(const Rational& other) const {
		int numer = numerator * other.numerator;
		int denom = denominator * other.denominator;
		return Rational(numer, denom);
	}

	Rational divide(const Rational& other) const {
		int numer = numerator * other.denominator;
		int denom = denominator * other.numerator;
		return Rational(numer, denom);
	}

	string toRationalString() const {
		return to_string(numerator) + "/" + to_string(denominator);
	}

	double toDouble() const {
		return static_cast<double>(numerator) / denominator;
	}

};

int main() {
	Rational r1(2, 5);
	Rational r2;

	Rational ratioAdd = r1.add(r2);
	Rational ratioSub = r1.subtract(r2);
	Rational ratioMul = r1.multiply(r2);
	Rational ratioDiv = r1.divide(r2);

	cout << "Rational 1: " << r1.toRationalString() << " = " << r1.toDouble() << endl;
	cout << "Rational 2: " << r2.toRationalString() << " = " << r2.toDouble() << endl;
	cout << "Rational 1 + Rational 2: " << ratioAdd.toRationalString() << " = " << ratioAdd.toDouble() << endl;
	cout << "Rational 1 - Rational 2: " << ratioSub.toRationalString() << " = " << ratioSub.toDouble() << endl;
	cout << "Rational 1 * Rational 2: " << ratioMul.toRationalString() << " = " << ratioMul.toDouble() << endl;
	cout << "Rational 1 / Rational 2: " << ratioDiv.toRationalString() << " = " << ratioDiv.toDouble() << endl;

}