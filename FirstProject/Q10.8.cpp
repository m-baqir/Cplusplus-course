#include <string>
#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(double realPart, double imaginaryPart) : real{ realPart }, imaginary{ imaginaryPart } { }

Complex Complex::operator+(const Complex& operand2) const {
	return Complex{ real + operand2.real,imaginary + operand2.imaginary };
}

Complex Complex::operator-(const Complex& operand2) const {
	return Complex{ real - operand2.real,imaginary - operand2.imaginary };
}
//this function is based on how two complex numbers are multiplied in algebra
//(a+bi).(c+di) = (ac - bd) + (ad+bc)i
Complex Complex::operator*(const Complex& operand2) const {
	double realPart = (real * operand2.real) - (imaginary * operand2.imaginary);
	double imaginaryPart = (real * operand2.imaginary) + (imaginary * operand2.real);
	return Complex(realPart, imaginaryPart);
}

bool Complex::operator==(const Complex& operand2) const {
	return (real == operand2.real) && (imaginary == operand2.imaginary);
}

bool Complex::operator!=(const Complex& operand2) const {
	return !(*this == operand2);
}

istream& operator>>(istream& input, Complex& complex) {
	input >> complex.real >> complex.imaginary;
	return input;
}
ostream& operator<<(ostream& output, const Complex& complex) {
	output << "(" << complex.real << ", " << complex.imaginary << ")";
	return output;
}

int main() {
	Complex x;
	Complex y{ 4.3,8.2 };
	Complex z{ 3.3,1.1 };

	x = y + z;
	cout << "Sum of " << y << " and " << z << " is " << x<<endl;
	x = y - z;
	cout << "Subtraction of " << y << " and " << z << " is " << x << endl;
	x = y * z;
	cout << "Multiplication of " << y << " and " << z << " is " << x << endl;

	if (y == z) {
		cout << y << " is equal to " << z<< endl;
	}
	else {
		cout << y << " is not equal to " << z << endl;
	}

	if (y != z) {
		cout << y << " is not equal to " << z << endl;
	}
	else {
		cout << y << " is equal to " << z << endl;
	}
}