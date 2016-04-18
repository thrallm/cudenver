// This program takes two numbers (pay rate & hours)
// and multiplies them to get grosspay    
// it then calculates net pay by subtracting 15%

// Mason Thrall

#include <iostream>
#include <iomanip>
using namespace std;

// Global constants
const float TAXRATE = 0.15;

//Function prototypes
void printDescription(); 
void computePaycheck(float, int, float, float); 

int main()
{
	float payRate;
	float grossPay;
	float netPay;
	int hours;
	
	cout << setprecision(2) << fixed;
	
	cout << "Welcome to the Pay Roll Program" << endl; 
	
	printDescription(); //Call to Description function
	
	cout << "Please input the pay per hour" << endl;
	cin >> payRate;
	
	cout << endl << "Please input the number of hours worked" << endl;
	cin >> hours;
	cout << endl << endl;
	
	computePaycheck(payRate,hours,grossPay,netPay);
	
	cout << "We hoped you enjoyed this program" << endl;
	
	return 0;
}

//   ********************************************************************
//                         printDescription
//   
//   task:     This function prints a program description
//   data in:  none
//   data out: none
//
//   ********************************************************************

void printDescription() //The function heading
{
	cout << "************************************************"  << endl << endl;
	cout << "This program takes two numbers (pay rate & hours)" << endl;
	cout << "and  multiplies them to get gross pay "            << endl;   
	cout << "it then calculates net pay by subtracting 15%"     << endl;
	cout << "************************************************"  << endl << endl;
}

//  *********************************************************************
//                        computePaycheck
//   
//   task:     This function takes rate and time and multiples them to
//             get gross pay and then finds net pay by subtracting 15%.
//   data in:  pay rate and time in hours worked
//   data out: the gross and net pay
//
//   ********************************************************************

void computePaycheck(float rate, int time, float gross, float net)
{ 
	gross = rate * time;
	net = gross - (gross * TAXRATE);
        cout << "The gross pay is $" << gross << endl;
        cout << "The net pay is $" << net << endl;
}
//
// Exercise 1: Program is now completed.
//
// Exercise 2: Program is tested with the given inputs and the output is correct.
//
// Exercise 3: The params gross and net are both pass by reference in the original version.
//
// Exercise 4: The program is now modified to print the values inside of computePaycheck.
// Since they don't need to be used outside of the function anymore, they are changed to pass by value
// in both the prototype and the function header.
//
// Exercise 5: I get the same output as exercise 2 when using pass by value in the modified program.
//
//
