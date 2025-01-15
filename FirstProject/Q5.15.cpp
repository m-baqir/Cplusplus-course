#include <iostream>
using namespace std;

int main() {
	//part a
	cout << "Part a" << endl;
	for (int i = 1; i <= 10;++i) {
		for (int j = 1;j <= i;++j) {
			cout << "*";
		}
		cout << endl;
	}
	//part b
	cout << "Part b" << endl;
	for (int i = 10; i >= 1;--i) {
		for (int j = 1;j <= i;++j) {
			cout << "*";
		}
		cout << endl;
	}
	//part c
	cout << "Part c" << endl;
	for (int i = 10; i >= 1;--i) {
		for (int j = 0;j < 10-i;++j) {
			cout << " ";
		}
		for (int j = 0;j < i;++j) {
			cout << "*";
		}
		cout << endl;
	}
	//part d
	cout << "Part d" << endl;
	for (int i = 1; i <= 10;++i) {
		for (int j = 0;j < 10 - i;++j) {
			cout << " ";
		}
		for (int j = 0;j < i;++j) {
			cout << "*";
		}
		cout << endl;
	}
}