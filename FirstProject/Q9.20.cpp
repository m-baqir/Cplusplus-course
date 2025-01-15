#include <iostream>
using namespace std;

class SavingsAccount {
private:
	double savingsBalance;
	static double annualInterestRate;
public:
	SavingsAccount(double balance) : savingsBalance(balance){}

	void calculateMonthlyInterest() {
		double monthlyInterest = (savingsBalance * annualInterestRate) / 12;
		savingsBalance += monthlyInterest;
	}

	static void modifyInterestRate(double newRate) {
		annualInterestRate = newRate;
	}

	void displayBalance() const {
		cout << "Current Balance: " << savingsBalance << endl;
	}
};

double SavingsAccount::annualInterestRate = 0.0;

int main() {
	SavingsAccount saver1(2000.0);
	SavingsAccount saver2(3000.0);
	SavingsAccount::modifyInterestRate(0.03);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	cout << "Balance after 3% interest rate: " << endl;
	saver1.displayBalance();
	saver2.displayBalance();
	SavingsAccount::modifyInterestRate(0.04);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	cout << "Balance after 4% interest rate: " << endl;
	saver1.displayBalance();
	saver2.displayBalance();
}