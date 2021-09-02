#include <iostream>
using namespace std;

class Rectangle
{
private:
	int length, width;

public:
	Rectangle(int l, int w); //constructor
	void area();
	void changeLength(int l);
	~Rectangle(); //desctructor
};

Rectangle::Rectangle(int l, int w)
{
	length = l;
	width = w;
}

void Rectangle::changeLength(int l)
{
	cout << "Length changed to " << l << "\n";
	length = l;
}

void Rectangle::area()
{
	cout << "Area of rectanlge: " << length * width << "\n";
}

Rectangle::~Rectangle()
{
	cout << "Done\n";
}

int main()
{
	Rectangle r(10, 5);
	r.area();
	r.changeLength(4);
	r.area();
	return 0;
}