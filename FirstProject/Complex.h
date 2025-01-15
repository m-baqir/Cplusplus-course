#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex {
public:
	explicit Complex(double = 0.0, double = 0.0);
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	bool operator==(const Complex&) const;
	bool operator!=(const Complex&) const;
	friend istream& operator>>(istream& input, Complex& complex);
	friend ostream& operator<<(ostream& output, const Complex& complex);
private:
	double real;
	double imaginary;
};
#endif
