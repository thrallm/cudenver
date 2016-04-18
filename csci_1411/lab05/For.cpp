//  This program has the user input a number n and then finds the
//  mean of the first n positive integers

// Mason Thrall

#include <iostream>
using namespace std;

int main()
{
	int startValue;  // startValue holds the number to start counting from
	int endValue;    // endValue holds the number to count up to
	int deltaValue;  // deltaValue contains the difference between startValue and endValue
 	int total = 0;   // total holds the sum of the first n positive numbers
   	int number;      // the amount of numbers
  	float mean;      // the average of the first n positive numbers

  	cout << "Please enter a positive integer to start from" << endl;
   	cin >> startValue;
	cout << "Please enter a positive integer to end at" << endl;
	cin >> endValue;


  	if (startValue > 0 && endValue > startValue)
  	{
		for (number = startValue; number <= endValue; number++) {
 	  		total += number;
		} 
		deltaValue = endValue - startValue + 1; // delta is the difference + 1
        	mean = static_cast<float>(total) / deltaValue;	
		cout << "The mean of the ints between " << startValue 
		     << " and " << endValue << " is " << mean << endl;
    	} else {
        	cout << "Invalid input - start value must be smaller "
		     << "than end value and both must be positive." << endl;
	}
	
	return 0;	
}
//
// Exercise 1: The typecast operator is needed to compute mean because both variables
// total and value are int types, so the natual division of them would be integer division
// and would produce an int instead of the desired float.
//
// If the typecast is removed, then integer division does indeed occur. If odd numbers are
// used, then integer division produces the correct output, however for even numbers the output
// is incorrect due to integer division.
//
// Exercise 2: If you enter a float into the program, it truncates the float to an int 
// (since value is an int) and uses that for the processing. For example 2.99 is truncated 
// to 2 and results in a mean of 1.5 (which is the correct mean for 2).
//
// Exercise 3: Code is modified so that the user can pick the startValue and endValue.
// The delta between the numbers endValue - startValue + 1.
// 	Ex. difference between 2 and 5 is 3, however there are actually 4 integers in this range:
// 	2,3,4,5. So the deltaValue needs to have + 1 in order to be accurate.
//
//
