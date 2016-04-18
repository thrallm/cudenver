// This program demonstrates a Binary Search

// Mason Thrall

#include <iostream>
using namespace std;

const int SIZE = 16;
const bool DEBUG = true;

int binarySearch(int [], int, int);  // function prototype

int main()
{
	int found, value;
	//int array[] = {34,19,19,18,17,13,12,12,12,11,9,5,3,2,2,0}; // descending sorted list
	int array[] = {0,2,2,3,5,9,11,12,12,12,13,17,18,19,19,34}; // ascending sorted list
	
	cout << "Enter an integer to search for:" << endl;
	cin >> value;

	found = binarySearch(array, SIZE, value); //function call to perform the binary search
	                                          //on array looking for an occurrence of value
	if (found == -1)
		cout << "The value " << value << " is not in the list" << endl;
	else
	{
		cout << "The value " << value << " is in position number "
		     << found + 1 << " of the list" << endl; 
	}
	return 0;
}


//*******************************************************************
//                     binarySearch
//
// task:	  This searches an array for a particular value
// data in:       List of values in an ordered array, the number of 
//                elements in the array, and the value searched for
//                in the array
// data returned: Position in the array of the value or -1 if value
//                not found
//
//*******************************************************************
int binarySearch(int array[],int numElems,int value) //function heading
{
	int first = 0;				// First element of list
	int last = numElems - 1;		// last element of the list
	int middle;				// variable containing the current
						// middle value of the list
	if(DEBUG)
		cout << "index\tvalue\n";

	while (first <= last){
		middle = first + (last - first) / 2;
		// add some code to see what the search is doing.
		if(DEBUG)
			cout << middle << "\t" << array[middle] << endl;
		if (array[middle] == value)
			return middle;		// if value is in the middle, we are done                   
		else if (array[middle] > value)
			last = middle - 1;	// toss out the second remaining half of
						// the array and search the first 
		else
			first = middle + 1;	// toss out the first remaining half of
						// the array and search the second
	}
	return -1;				// indicates that value is not in the array
}
// Exercise 1: The right side of the statement is referring to an int because this is integer 
// division. The middle value is found by:
// * finding the difference between last and first
// * dividing this by 2 using integer division to get the halfway value for a delta of this size
// * adding this halfway point to the first integer to offset it based on the first value.
// This middle value affects the logic of the program since it is the index of the value to compare to
// the search value (named value). The value at that index is either the correct value, or too large or 
// too small. Depending on the result of this comparison, either the value is returned, or first or last
// is adjusted to narrow the portion of the array indicies to search in the next loop.
//
// Exercise 2:
// * The position of 19 which is returned is 2 (index 1). This is the first occurance.
// * The position of 12 which is returned is 8 (index 7). This is the second occurance.
// * For 19, the first middle value is 12 (index 7), so it is higher, then the 2nd middle value is 
// 18 (index 3) so it is higher, then the third middle value is 19 (index 1) so it is returned.
// * For 12, it is the first value of middle (index 7) so it is immediately returned.
// * The difference is just caused by the splitting of the array and which index of the repeated value
// happens to be on a middle index first. Since the middle indexes in a array of 16 elements will be
// 7 then {3||11} then {1||13},etc... then the values in those indicies will be returned earlier in the algorithm.
//
// Exercise 3: Program is modified to search an ascending sorted array instead.
