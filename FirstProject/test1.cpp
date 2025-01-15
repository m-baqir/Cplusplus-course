#include <iostream>
using namespace std;
int main() {
	int n;
	cout << "enter an even integer between 10 and 30";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "*";
	}
	cout << endl;
	for (int i = 1; i <= n - 2;i++) {
		if (i % 2 == 1) {
			cout << '*';
			for (int j = 1;j <= n - 2;j++) {
				cout << " ";
			}
			cout << endl;
		}
		else {
			for (int j = 1;j <= n - 2;j++) {
				cout << ' ';
			}
			cout << '*';
			cout << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "*";
	}

}