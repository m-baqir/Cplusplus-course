#include <iostream>
#include <sstream>
using namespace std;

class RationalNumber {
private:
	int numerator, denominator;

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
	RationalNumber(int numer = 1, int denom = 1) :numerator(numer) {
		if (denom == 0) {
			cout << "Error: Denominator cannot be 0" << endl;
			exit(1);
		}
		denominator = denom;
		reduceFrac();
	}

	RationalNumber operator+(const RationalNumber& other) const {
		int numer = numerator * other.denominator + other.numerator * denominator;
		int denom = denominator * other.denominator;
		return RationalNumber(numer, denom);
	}

	RationalNumber operator-(const RationalNumber& other) const {
		int numer = numerator * other.denominator - other.numerator * denominator;
		int denom = denominator * other.denominator;
		return RationalNumber(numer, denom);
	}

	RationalNumber operator*(const RationalNumber& other) const {
		int numer = numerator * other.numerator;
		int denom = denominator * other.denominator;
		return RationalNumber(numer, denom);
	}

	RationalNumber operator/(const RationalNumber& other) const {
		if (other.numerator == 0) {
			cout << "Error: Cannot divide by 0" << endl;
			exit(1);
		}
		int numer = numerator * other.denominator;
		int denom = denominator * other.numerator;
		return RationalNumber(numer, denom);
	}

	bool operator==(const RationalNumber& other) const {
		return numerator == other.numerator && denominator == other.denominator;
	}

	bool operator!=(const RationalNumber& other) const {
		return !(*this == other);
	}

	bool operator<(const RationalNumber& other) const {
		return numerator * other.denominator < other.numerator * denominator;
	}

	bool operator<=(const RationalNumber& other) const {
		return *this < other || *this == other;
	}

	bool operator>(const RationalNumber& other) const {
		return numerator * other.denominator > other.numerator * denominator;
	}

	bool operator>=(const RationalNumber& other) const {
		return *this > other || *this == other;
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
	RationalNumber r1(2, 5);
	RationalNumber r2(5, 6);

	cout << "Rational number 1: " << r1.toRationalString() << " = " << r1.toDouble() << endl;
	cout << "Rational number 2: " << r2.toRationalString() << " = " << r2.toDouble() << endl;

	RationalNumber ratioAdd = r1+r2;
	RationalNumber ratioSub = r1-r2;
	RationalNumber ratioMul = r1*r2;
	RationalNumber ratioDiv = r1/r2;
	cout << "Rational 1 + Rational 2: " << ratioAdd.toRationalString() << " = " << ratioAdd.toDouble() << endl;
	cout << "Rational 1 - Rational 2: " << ratioSub.toRationalString() << " = " << ratioSub.toDouble() << endl;
	cout << "Rational 1 * Rational 2: " << ratioMul.toRationalString() << " = " << ratioMul.toDouble() << endl;
	cout << "Rational 1 / Rational 2: " << ratioDiv.toRationalString() << " = " << ratioDiv.toDouble() << endl;

	if (r1 == r2) {
		cout << "R1 is equal to R2: true" << endl;
	}
	else {
		cout << "R1 is equal to R2: false" << endl;
	}
	if (r1 != r2) {
		cout << "R1 is not equal to R2: true" << endl;
	}
	else {
		cout << "R1 is not equal to R2: false" << endl;
	}
	if (r1 < r2) {
		cout << "R1 is less than R2: true" << endl;
	}
	else {
		cout << "R1 is less than R2: false" << endl;
	}
	if (r1 <= r2) {
		cout << "R1 is less than or equal R2: true" << endl;
	}
	else {
		cout << "R1 is less than or equal R2: false" << endl;
	}
	if (r1 > r2) {
		cout << "R1 is greater than R2: true" << endl;
	}
	else {
		cout << "R1 is greater than R2: false" << endl;
	}
	if (r1 >= r2) {
		cout << "R1 is greater than or equal to R2: true" << endl;
	}
	else {
		cout << "R1 is greater than or equal to R2: false" << endl;
	}
}