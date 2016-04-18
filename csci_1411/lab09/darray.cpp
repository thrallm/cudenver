// This program demonstrates the use of dynamic arrays

// Mason Thrall

#include <iostream>
#include <iomanip>
using namespace std;


int main(){
	float *monthSales;		// a pointer used to point to an array
					// holding monthly sales
	float total = 0;		// total of all sales
	float average;			// average of monthly sales
	int numOfSales;			// number of sales to be processed
	int count;			// loop counter

	cout << fixed << showpoint << setprecision(2);

	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;
	cin.ignore();

	// Fill in the code to allocate memory for the array pointed to by
	// monthSales.
	monthSales = new float[numOfSales]; 	// I tried new float(numOfSales), 
						// but kept getting runtime pointer
						// errors. Square brackets seem
						// to work fine.

	if(monthSales == NULL){
		cout << "Error allocating memory!\n";
		return 1;
	}

	cout << "Enter the sales below\n";

	for(count = 0; count < numOfSales; count++){
  		cout << "Sales for Month number  " 
		     << count
		     << ": ";
		// Fill in code to bring sales into an element of the array
		cin >> monthSales[count];
	}

	for(count = 0; count < numOfSales; count++){
		total +=  monthSales[count];
	}

	average = total / numOfSales;


	cout << "Average Monthly sale  is $" << average << endl;
	// Fill in the code to deallocate memory assigned to the array.
	delete [] monthSales;
	return 0;
}
// Code complete.
