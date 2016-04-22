// CSCI 1411-003
// Lab 13
// Question 13.5
// Impletment a SavingsAccount simulation class.
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
#include <cmath>
using namespace std;

class SavingsAccount {
public:
	SavingsAccount();
	SavingsAccount(float f);
	~SavingsAccount();
	void depositMoney(float f);
	void withdrawMoney(float f);
	void showBalance();
private:
	int calcDollars(float f);
	int calcCents(float f);
	void addMoney(int d, int c);
	void subtractMoney(int d, int c);
	int dollars;
	int cents;
};

int main() {
	float amount;
	char choice;
	cout << "Please enter the initial Deposit:\n";
	cin >> amount;
	cin.ignore();
	SavingsAccount bank1(amount); // open the account1
	SavingsAccount bank2; // open the account2
	// process deposits
	do{
		cout << "Do you want to make a deposit?\n";
		cin.get(choice);
		cin.ignore();
		if(toupper(choice) == 'Y') {
			cout << "Please enter the amount to deposit:\n";
			cin >> amount;
			cin.ignore();
			bank1.depositMoney(amount);
			bank2.depositMoney(amount);
		}
	} while (toupper(choice) == 'Y');
	// process withdrawls
	do{
		cout << "Do you want to make a withdraw?\n";
		cin.get(choice);
		cin.ignore();
		if(toupper(choice) == 'Y') {
			cout << "Please enter the amount to withdraw:\n";
			cin >> amount;
			cin.ignore();
			bank1.withdrawMoney(amount);
			bank2.withdrawMoney(amount);
		}
	} while (toupper(choice) == 'Y');
	cout << "Account with initial deposit:\n";
	bank1.showBalance();
	cout << "Account without initial deposit:\n";
	bank2.showBalance();
	return 0;
}

// SavingsAccount:: default constructor
SavingsAccount::SavingsAccount() {
	dollars = 0;
	cents = 0;
}

// SavingsAccount:: constructor
SavingsAccount::SavingsAccount(float f) {
	int d = calcDollars(f);
	int c = calcCents(f);
	dollars = d;
	cents = c;
}

// SavingsAccount:: destructor
SavingsAccount::~SavingsAccount() {
	cout << "Done using SavingsAccount!\n";
}

// SavingsAccount::depositMoney
void SavingsAccount::depositMoney(float f) {
	int d = calcDollars(f);
	int c = calcCents(f);
	addMoney(d, c);
}

// SavingsAccount::withdrawMoney
void SavingsAccount::withdrawMoney(float f) {
	int d = calcDollars(f);
	int c = calcCents(f);
	subtractMoney(d, c);
}

// SavingsAccount::showBalance
void SavingsAccount::showBalance() {
	cout << "Dollars: " << dollars << " Cents: " << cents << endl;
}

// SavingsAccount::calcDollars
int SavingsAccount::calcDollars(float f) {
	int d = f;
	return d;
}

// SavingsAccount::calcCents
int SavingsAccount::calcCents(float f) {
	int c = ceil(f * 100);
	return c % 100;
}

// SavingsAccount::addMoney
void SavingsAccount::addMoney(int d, int c) {
	int temp = cents + c;
	dollars += d + (temp / 100);
	cents = (temp % 100);
}

// SavingsAccount::subtractMoney
void SavingsAccount::subtractMoney(int d, int c) {
	int temp = cents - c;
	if (temp >= 0) {
		dollars -= d;
		cents = temp;
	} else if (temp < 0) {
		dollars -= (d + 1);
		cents = 100 + temp;
	}
}