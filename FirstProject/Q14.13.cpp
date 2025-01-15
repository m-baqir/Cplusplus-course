#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main() {
	ofstream outputF("data-size.dat");
	if (!outputF) {
		cerr << "Error: file cannot be opened" << endl;
	}
	outputF << left << setw(20) << "Type" << right << setw(10) << "Size (bytes)" << endl;
	outputF << "-----------------------------------------" << endl;
	outputF << left << setw(20) << "char" << right << setw(10) << sizeof(char) << endl;
	outputF << left << setw(20) << "unsigned char" << right << setw(10) << sizeof(unsigned char) << endl;
	outputF << left << setw(20) << "short int" << right << setw(10) << sizeof(short int) << endl;
	outputF << left << setw(20) << "unsigned short int" << right << setw(10) << sizeof(unsigned short int) << endl;
	outputF << left << setw(20) << "int" << right << setw(10) << sizeof(int) << endl;
	outputF << left << setw(20) << "unsigned int" << right << setw(10) << sizeof(unsigned int) << endl;
	outputF << left << setw(20) << "long int" << right << setw(10) << sizeof(long int) << endl;
	outputF << left << setw(20) << "unsigned long int" << right << setw(10) << sizeof(unsigned long int) << endl;
	outputF << left << setw(20) << "float" << right << setw(10) << sizeof(float) << endl;
	outputF << left << setw(20) << "double" << right << setw(10) << sizeof(double) << endl;
	outputF << left << setw(20) << "long double" << right << setw(10) << sizeof(long double) << endl;

	outputF.close();

}