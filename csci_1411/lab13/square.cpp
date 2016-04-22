// Mason Thrall

#include <iostream>
using namespace std;

class Square{
public:
	void setSide(float);
	void printSquareInfo();
	float findArea();
	float findPerimeter();
	Square();
	Square(int len);
	~Square();
private:
	float side;
};

int main()
{
	Square box, box1(9);      
	float size;
	// get info about the box
	cout << "What is the length of the side of the square?\n";
	cin >> size;
	box.setSide(size);

	// print out data about the box
	cout << "box info:\n";
	box.printSquareInfo();
	cout << endl << endl;
	cout << "box1 info:\n";
	box1.printSquareInfo();
	return 0;
}

//**************************************************
//                 Default Constructor
//***************************************************	
Square::Square()
{
	side = 1;
}

//**************************************************
//                 Constructor
//***************************************************	
Square::Square(int len)
{
	side = len;
}

//**************************************************
//                 Destructor
//***************************************************	
Square::~Square()
{
}

//**************************************************
//                  setSide
//
// task:    This procedure takes the length of a side and
//          places it in the appropriate member data
// data in: length of a side
//***************************************************

void Square::setSide(float length)
{
	side = length;
}
//**************************************************
//                 findArea
//
// task:    This finds the area of a square
// data in: none (uses value of data member side)
// data returned:  area of square
//***************************************************

float Square::findArea()
{
	return side * side;
}
//**************************************************
//                 findPerimeter
//
// task:    This finds the perimeter of a square
// data in: none (uses value of data member side)
// data returned:  perimeter of square
//***************************************************	
float Square::findPerimeter()
{
	return 4 * side;
}


//***************************************************
//                printSquareInfo
//***************************************************
void Square::printSquareInfo() {
	cout << "The area of the square is: ";
	cout << findArea() << endl;
	cout << "The perimeter of the square is: ";
	cout << findPerimeter() << endl;
}