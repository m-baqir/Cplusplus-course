#include <iostream>
using namespace std;

class Account {
protected:
	double balance;
public:
	Account(double initialBalance) {
		if (initialBalance >= 0.0) {
			balance = initialBalance;
		}
		else {
			balance = 0.0;
			cout << "Invalid initial balance." << endl;
		}
	}
	void credit(double amount) {
		balance += amount;
	}
	bool debit(double amount) {
		if (amount > balance) {
			cout << "Debit amount exceeded account balance." << endl;
			return false;
		}
		else {
			balance -= amount;
			return true;
		}
	}
	double getBalance() {
		return balance;
	}
};

class SavingsAccount :public Account {
private:
	double interestRate;
public:
	SavingsAccount(double initialBalance, double rate) :Account(initialBalance) {
		interestRate = rate;
	}
	double calculateInterest() {
		return balance * interestRate;
	}
};

class CheckingAccount :public Account {
private:
	double transactionFee;
public:
	CheckingAccount(double initialBalance, double fee) :Account(initialBalance) {
		transactionFee = fee;
	}
	void credit(double amount) {
		Account::credit(amount);
		balance -= transactionFee;
	}
	bool debit(double amount) {
		if (Account::debit(amount)) {
			balance -= transactionFee;
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	SavingsAccount savings(1500.0, 0.02);
	CheckingAccount checking(300, 2.0);
	cout << "Initial savings account balance: " << savings.getBalance() << endl;
	savings.credit(200.0);
	cout << "Balance after credit: " << savings.getBalance() << endl;
	savings.debit(150.0);
	cout << "Balance after debit: " << savings.getBalance() << endl;
	double myInterest = savings.calculateInterest();
	cout << "Interest earned: " << myInterest << endl;
	savings.credit(myInterest);
	cout << "Balance after interest: " << savings.getBalance() << endl;

	cout << "Initial checking account balance: " << checking.getBalance() << endl;
	checking.credit(150.0);
	cout << "Balance after credit: " << checking.getBalance() << endl;
	checking.debit(30.0);
	cout << "Balance after debit: " << checking.getBalance() << endl;
}