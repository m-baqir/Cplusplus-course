#include <iostream>
using namespace std;

int main() {
	const int len = 1000;
	int primeArray[len];

	for (int i = 0; i < len;i++) {
		primeArray[i] = 1;
	}

	for (int j = 2; j < len;j++) {
		if (primeArray[j] == 1) {
			for (int k = j * j;k < len;k += j) {
				primeArray[k] = 0;
			}
		}
	}

	cout << "The prime numbers between 2 and 999 are: " << endl;

	for (int i = 2;i < len;i++) {
		if (primeArray[i] == 1) {
			cout << i << " ";
		}
	}

}