// This program shows how the toupper and tolower functions can be
// applied in a C++ program

#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{
	int week, total, dollars;
	float average;
	char choice;

	cout << showpoint << fixed << setprecision(2);

	do
	{
		total = 0;
		for(week = 1;week <= 4;week++)
		{
			cout << "How much (to the nearest dollar) did you"
				 <<" spend on food during week " << week << " ?:" << endl;
			cin >> dollars;

			total = total + dollars;
		}
		average = total / 4.0;

		cout << "Your weekly food bill over the chosen month is $"
			 << average << endl << endl;
		do
		{
		   cout << "Would you like to find the average for another month?";
		   cout << endl << "Enter Y or N" << endl;
		   cin >> choice;
		} while(tolower(choice) != 'y' && tolower(choice) != 'n'); 

	} while (tolower(choice) == 'y');
	
	
	return 0;
}
//
// Exercise 1: Ran with various inputs.
//
// Exercise 2: This inner do-while loop is a input validator. All it is doing is checking that you
// enter 'y', 'Y', 'n', or 'N'. If you don't, then it asks you over and over. If it were removed,
// then the input could be values which are not 'Y' or 'N', which means that the containing loop would
// exit for all values except 'y' or 'Y'. I tested it, and this is exactly what happens.
//
// Exercise 3: The program is modified to use tolower() instead of toupper().
