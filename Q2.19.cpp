#include <iostream>
using namespace std;
int main()
{
	int x, y, z;
	cout << "Input three different integers: ";
	cin >> x >> y >> z;
	cout << "Sum is " << x + y + z << endl;
	cout << "Average is " << (x + y + z) / 3 << endl;
	cout << "Product is " << x * y * z << endl;
	int smallest = x, largest = x;
	if (y < smallest)
		smallest = y;
	if (z < smallest)
		smallest = z;
	if (y > largest)
		largest = y;
	if (z > largest)
		largest = z;
	cout << "Smallest is " << smallest << endl;
	cout << "Largest is " << largest << endl;
}