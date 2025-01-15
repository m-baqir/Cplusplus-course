#include <iostream>
#include<sstream>
using namespace std;

class Rational {
private:
	int denominator, numerator;

	int gcd(int a, int b) const {
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

	Rational add(const Rational r1, const Rational r2) {
		int numer = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
		int denom = r1.denominator * r2.denominator;
		return Rational(numer, denom);
	}

	Rational subtract(const Rational r1, const Rational r2) {
		int numer = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
		int denom = r1.denominator * r2.denominator;
		return Rational(numer, denom);
	}

	Rational multiply(const Rational r1, const Rational r2) {
		int numer = r1.numerator * r2.numerator;
		int denom = r1.denominator * r2.denominator;
		return Rational(numer, denom);
	}

	Rational divide(const Rational r1, const Rational r2) {
		int numer = r1.numerator * r2.denominator;
		int denom = r1.denominator * r2.numerator;
		return Rational(numer, denom);
	}

	string toRationalString() const {
		ostringstream output;
		output << numerator << "/" << denominator;
		return output.str();
	}

	double toDouble() const {
		return static_cast<double>(numerator) / denominator;
	}

};

int main() {
	Rational r1(2, 5);
	Rational r2;

	Rational ratioAdd = r1.add(r1,r2);
	Rational ratioSub = r1.subtract(r1,r2);
	Rational ratioMul = r1.multiply(r1,r2);
	Rational ratioDiv = r1.divide(r1,r2);

	cout << "Rational 1: " << r1.toRationalString() << " = " << r1.toDouble() << endl;
	cout << "Rational 2: " << r2.toRationalString() << " = " << r2.toDouble() << endl;
	cout << "Rational 1 + Rational 2: " << ratioAdd.toRationalString() << " = " << ratioAdd.toDouble() << endl;
	cout << "Rational 1 - Rational 2: " << ratioSub.toRationalString() << " = " << ratioSub.toDouble() << endl;
	cout << "Rational 1 * Rational 2: " << ratioMul.toRationalString() << " = " << ratioMul.toDouble() << endl;
	cout << "Rational 1 / Rational 2: " << ratioDiv.toRationalString() << " = " << ratioDiv.toDouble() << endl;

}