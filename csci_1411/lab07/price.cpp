// This program will read in prices and store them into a two-dimensional array
// It will print those prices in a table form.

// Mason Thrall

#include <iostream>
#include <iomanip>
using namespace std;

// constants
const int MAXROWS = 10;
const int MAXCOLS = 10;
// array types
typedef float PriceType[MAXROWS][MAXCOLS];	// creates a new data type
						// of a 2D array of floats
// function protoypes
void getPrices(PriceType, int&, int&);	// gets the prices into the array
void printPrices(PriceType, int, int);	// prints data as a table
float findHighestPrice(PriceType, int, int); // returns the highest price
float findLowestPrice(PriceType, int, int); // returns the lowest price

int main(){
	int rowsUsed;                               // holds the number of rows used 
	int colsUsed;                               // holds the number of columns used
	PriceType priceTable;                       // a 2D array holding the prices

	getPrices(priceTable, rowsUsed, colsUsed);  // calls getPrices to fill the array
	printPrices(priceTable, rowsUsed, colsUsed);// calls printPrices to display array
	cout << endl << "Highest price is " << findHighestPrice(priceTable, rowsUsed, colsUsed) << endl;
	cout << endl << "Lowest price is " << findLowestPrice(priceTable, rowsUsed, colsUsed) << endl;
	return 0;
}

//*********************************************************************************
//                           getPrices
//
//  task:     This procedure asks the user to input the number of rows and
//            columns. It then asks the user to input (rows * columns) number
//            of prices where x = rows * columns.  The data is placed in the array.
//  data in:  none
//  data out: an array filled with numbers and the number of rows 
//            and columns used.
//
//********************************************************************************

void getPrices(PriceType table, int& numOfRows, int& numOfCols){
	cout << "Please input the number of rows from 1 to " << MAXROWS << endl;
	cin >> numOfRows;
	cout << "Please input the number of columns from 1 to " << MAXCOLS << endl;
	cin >> numOfCols;
	for (int row = 0; row < numOfRows; row++){
		for (int col = 0; col < numOfCols;  col++){
			cout << "Please input the price of an item with 2 decimal places\n";
			cin >> table[row][col];
		}
	}
}

//***************************************************************************
//                           printPrices
//
//  task:     This procedure prints the table of prices
//  data in:  an array of floating point numbers and the number of rows
//			  and columns used.
//  data out: none
//
//****************************************************************************

void printPrices(PriceType table, int numOfRows, int numOfCols){
	cout << fixed << showpoint << setprecision(2);
	for (int row = 0;  row < numOfRows; row++)
	{
		for (int col = 0;  col < numOfCols; col++){
			cout << "\t" << table[row][col];
		}
		cout << "\n";
	}
}

//***************************************************************************
//			findHighestPrice
//
// task: This function returns the highest price in the array.
// data in: A priceType array called table, ints for numOfCols and numOfRows.
// data out: the highest price, a float.
//
//***************************************************************************

float findHighestPrice(PriceType table, int numOfRows, int numOfCols){
	float highest;
	highest = table[0][0];
	for(int row = 0; row < numOfRows; row++){
		for(int col = 0;col < numOfCols; col++){
			highest < table[row][col] ? highest = table[row][col] : highest = highest;
		}
	}
	return highest;
}

//***************************************************************************
////                      findLowestPrice
////
//// task: This function returns the lowest price in the array.
//// data in: A priceType array called table, ints for numOfCols and numOfRows.
//// data out: the lowest price, a float.
////
////***************************************************************************
float findLowestPrice(PriceType table, int numOfRows, int numOfCols){
	float lowest;
	lowest = table[0][0];
	for(int row = 0; row < numOfRows; row++){
		for(int col = 0;col < numOfCols; col++){
			lowest > table[row][col] ? lowest = table[row][col] : lowest = lowest;
		}
	}
	return lowest;
}
//
// Exercise 1: Program is complete and the results match the assignment values.
//
// Exercise 2: The function getPrices has numOfRows and numOfCols passed by reference because
// this function needs to edit these values. In printPrices, they are passed by value because
// it just needs to read these variables.
//
// Exercise 3: The program is modified to include highestPrice and to call it and 
// print the highest price.
//
// Exercise 4: The findLowestPrice function is added.
// 
// Exercise 5: The new program returns the following.
// Please input the number of rows from 1 to 10
// 2
// Please input the number of columns from 1 to 10
// 3
// Please input the price of an item with 2 decimal places
// 1.45
// Please input the price of an item with 2 decimal places
// 2.56
// Please input the price of an item with 2 decimal places
// 12.98
// Please input the price of an item with 2 decimal places
// 37.86
// Please input the price of an item with 2 decimal places
// 102.34
// Please input the price of an item with 2 decimal places
// 67.89
//         1.45    2.56    12.98
//                 37.86   102.34  67.89
//
//                 Highest price is 102.34
//
//                 Lowest price is 1.45
//
