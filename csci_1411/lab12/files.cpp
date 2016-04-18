// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.
// Mason Thrall

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Fill in the code to define payfile as an input file
	ifstream payFile;
	float gross;
	float net;
	float hours;
	float payRate;
    	float stateTax;
	float fedTax;

	cout << fixed << setprecision(2) << showpoint;
	// FILL IN THE CODE TO OPEN payfile AND ATTACH IT TO THE PHYSICAL FILE
    	// NAMED payroll.dat
    	payFile.open("payroll.dat");

	// FILL IN CODE TO WRITE A CONDITIONAL STATEMENT TO CHECK IF payfile 
	// DOES NOT EXIST.
	if (!payFile)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	cout << "Payrate      Hours    Gross Pay       Net Pay" << endl << endl;
     	// FILL IN CODE TO PRIME THE READ FOR THE payfile FILE.
     	payFile >> hours >> payRate >> stateTax >> fedTax;
     	// FILL IN CODE TO WRITE A LOOP CONDITION TO RUN WHILE payfile HAS MORE 
     	// DATA TO PROCESS.
     	while (!payFile.eof()) {	
	   	gross = payRate * hours;
	   	net = gross - (gross * stateTax) - (gross * fedTax);
	   	cout << payRate << setw(15) << hours << setw(12) << gross
                     << setw(12) << net << endl;
	   	payFile >> hours >> payRate >> stateTax >> fedTax;
	}
      	payFile.close();
     	return 0;
}
