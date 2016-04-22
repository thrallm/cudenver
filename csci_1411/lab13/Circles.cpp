// Mason Thrall

#include <iostream>
using namespace std;
//_________________________________________________________________________
// This program declares a class for a circle that will have 
// member functions that set the center, find the area, find
// the circumference and display these attributes.
// The program as written does not allow the user to input data, but
// rather has the radii and center coordinates of the circles (spheres in the program) 
// initialized  at declaration or set by a function.

//class declaration section   (header file)

class Circles
{
public:
	double findArea();
	double findCircumference();
	void printCircleStats();
	Circles(float r);
	Circles(float r, int x, int y);
	Circles();
	~Circles();
private:
	float  radius;
	int    center_x;
	int    center_y;
};

const double PI = 3.14;

//Client section   

int main()
{
	Circles sphere1(2), sphere2;
	cout << "sphere1 stats:\n";
	sphere1.printCircleStats();
	cout << "sphere2 stats:\n";
	sphere2.printCircleStats();
	return 0;
}

//___________________________________________________________________________
//Implementation section     Member function implementation

Circles::Circles()
{
	radius = 1;
	center_x = 0;
	center_y = 0;
}
Circles::~Circles()
{
	cout << "This concludes the Circles class!\n";
}
// Fill in the code to implement the non-default constructor
Circles::Circles(float r) {
	radius = r;
	center_x = 0;
	center_y = 0;
}
Circles::Circles(float r, int x, int y)
{
	radius = r;
	center_x = x;
	center_y = y;
}
// Fill in the code to implement the findArea member function
double Circles::findArea() {
	return PI * radius * radius;
}
// Fill in the code to implement the findCircumference member function
double Circles::findCircumference() {
	return 2 * PI * radius;
}


void Circles::printCircleStats()
// This procedure prints out stats about the Circle.
{
	cout << "The radius of the circle is " << radius << endl;
	cout << "The center of the circle is (" << center_x
		 << "," << center_y << ")" << endl;
	cout << "The area of the circle is " << findArea() << endl;
	cout << "The circumference of the circle is "
		 << findCircumference() << endl;
}

// Exersize 1: Code is modified to set private member variables during the Constructor. 
// This doesn't really affect what happens in main though since they get overwritten
// immediately after construction.
// Exersize 2: Code is modified to add the additional constructor. The setCenter member function is removed, and all 
// Circles instances now use one of the constructors to set thier member variables.
// Exersize 4: The destructor is added. It prints out the message 2 times because there are two instances
// of the Circles class. Each one is destroyed when the program exists, thus the destructor is called for each one.