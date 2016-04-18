// This program illustrates the use of logical operators
// name: Mason Thrall

#include <iostream>
using namespace std;


int main()
{
 	char year;
	float gpa;

	cout << "What year student are you ?" << endl;
	cout << "Enter 1 (freshman), 2 (sophomore), 3 (junior), or 4 (senior)" << endl << endl;
	cin >> year;

	cout << "Now enter your GPA" << endl;
	cin >> gpa;

	if (gpa >= 2.0 && year == '4')
		cout << "It is time to graduate soon" << endl;
        else if (year != '4' || gpa < 2.0)
		cout << "You need more schooling" << endl;

	return 0;
}

// Exercise 1:
// You could rewrite gpa >= 2.0 in the first if statement like !(gpa < 2.0) which means that the gpa
// is not less than 2.0. You add parenthesis so that the output of the relational operator is reversed,
// then switch the direction of the comparison to less than and remove the equals since the bad grade
// doesn't include 2.0
//
// Exercise 2:
// You can't replace the year != '4' in the else if with year < 4 or year <= 3 because those are comparing
// to integers. The year variable is a character. It would likely still evaluate, but it would use the
// ASCII value of the char, which is not what would be expected.
//
// Exercise 3:
// If you do this replacement, then:
// 	* Everyone in year 4 will graduate.
// 	* Everyone with gpa greater than 2.0 will graduate.
// 	* Everyone with both gpa less than 2.0 and not in year 4 will not graduate.
// 	* This does seem to cover all cases as seen below.
//
//	ORIGINAL truth table:
//	gpa     y1      y2      y3      y4
//	1       no      no      no      no
//	2       no      no      no      yes
//	3       no      no      no      yes
//	4       no      no      no      yes
//
//	WITH THE CHANGE truth table:
//	gpa 	y1	y2	y3	y4
//	1	no	no	no	yes
//	2	yes	yes	yes	yes
//	3	yes	yes	yes	yes
//	4	yes	yes	yes	yes
//	
// Exercise 4:
// Yes you can replace else if (year != '4' || gpa < 2.0) with just else in this case. This is because
// The else if handles all other cases. It would be good to add input validation though, since
// The "You need more schooling" will display if the year is '5' or the gpa is < 0.
