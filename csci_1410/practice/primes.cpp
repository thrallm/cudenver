// <description of file>
// Author: Mason Thrall, mason.thrall@ucdenver.edu
#include <iostream>
using namespace std;

int main() {
	int number = 0, maxCount;
	cout << "How high to check primes to?" << endl;
	cin >> maxCount;
	cout << "OK, here we go!" << endl;
	for (int i = 0; i <= maxCount; i++) { 
		if (number <= 2) {
			cout << number << " ";
		}
		for (int j = 2; j < number; j++) {
			if ((number % j) == 0) {	
				break;
			} else if ( j == (number - 1) ) {
				cout << number << " ";	
			} else {
				continue;
			}
		}
		number += 1;
  	}
	cout << endl;
	return 0;
}
