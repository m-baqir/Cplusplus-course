#include <iostream>
using namespace std;
int main()
{
	double x, y;
	std::cout << "Enter two numbers: ";
	std::cin >> x >> y;
	std::cout << "Sum: " << x + y << std::endl;
	std::cout << "Product: " << x * y << std::endl;
	std::cout << "Difference: " << x - y << std::endl;
	std::cout << "Quotient: " << x / y << std::endl;
}