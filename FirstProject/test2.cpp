#include <iostream>
using namespace std;
int main() {
	const int SIZE = 10;
	int arr[SIZE];
	int count = 0;
	int i = 0;

	while (i < SIZE) {
		cout << "Enter an integer: ";
		cin >> arr[i];
		i++;
	}

	for (int num : arr) {
		if (num > 100) {
			count++;
		}
	}
	cout << "number of integers greater then 100: " << count << endl;
}