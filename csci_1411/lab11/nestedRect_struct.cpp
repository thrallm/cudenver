#include <iostream>
#include <iomanip>
using namespace std;

// This program uses a structure to hold data about a rectangle 
// It calculates the area and perimeter of a box 

// Mason Thrall

// structs
struct Dimensions {
	float length, width;
};

struct Results {
	float area, perimeter;
};

struct Rectangle {
	Dimensions sizes;
	Results attributes;
};

// prototypes
void computeArea(Rectangle &r);
void computePerimeter(Rectangle &r);

int main() {

	Rectangle box;

   	cout << "Enter the length of a rectangle: ";  
	cin >> box.sizes.length;

	cout << "Enter the width of a rectangle: ";
	cin >> box.sizes.width;

	cout << endl << endl;

	computeArea(box);
	computePerimeter(box);

	cout << fixed << showpoint << setprecision(2);
	cout << "The area of the rectangle is " << box.attributes.area << endl; 
	cout << "The perimeter of the recangle is " <<  box.attributes.perimeter << endl;

	return 0;
}
//*******************************************
// computeArea(Rectangle)
// compute the area for the rectangle and put 
// it in the area member variable.
//*******************************************
void computeArea(Rectangle &r){
	r.attributes.area = r.sizes.length * r.sizes.width;
}

//*******************************************
// computePerimeter(Rectangle)
// compute the perimeter for the rectangle and put
// it in the perimeter member variable.
//*******************************************
void computePerimeter(Rectangle &r){
	r.attributes.perimeter = 2 * (r.sizes.length + r.sizes.width);
}

// Exercise 1: Code is complete.
// Exercise 2: Code is modified to add the Results struct.
// Exercise 3: Functions are added to compute the area and perimeter.
