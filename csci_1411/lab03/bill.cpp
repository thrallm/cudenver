// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// name: Mason Thrall

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()

{
	int   quantity;			// contains the amount of items purchased
	float itemPrice;		// contains the price of each item
	float totalBill;		// contains the total bill.  
	string productName;		// contains the name of the product.


	cout << setprecision(2) << fixed << showpoint;  //formatted output
	
	// Ask for the name of the product.
	cout << "Please input the name of the product:" << endl;
	// Get the name of the product.
	getline(cin, productName);
	
	// Get the number of items bought.
	cout << "Please input the number of items bought:" << endl;   

	// Fill in the input statement to bring in the quantity. 
	cin >> quantity;

	// Fill in the prompt to ask for the price.
	cout << "Please input the price of each item:" << endl;

	// Fill in the input statement to bring in the price of each item.
	cin >> itemPrice;

	// Fill in the assignment statement to determine the total bill.
	totalBill = quantity * itemPrice;

	// Fill in the output statement to print total bill,
	// with a label to the screen.
	cout << "The name of the product is " << productName << endl;
	cout << "The total bill is $" << totalBill << endl;

	return 0;
}
/*
Exercise 2:
When you run with  setprecision(2) << fixed << showpoint you get 241.56, 
but if you remove fixed, then you get 2.4e+02 instead. It seems that fixed formats
the number as a decimal format instead of scientific notation. 

Exercise 3:
After changing the setprecision(4) the program output 241.5600,
it seems that setprecision sets the number of digits to display after the radix point.

Exercise 4:
I added #include<string> so now you can set the name of the product.
I also used getline(cin, productName) to get the whole line including spaces.
*/
