#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
	int length, width;

public:
	//overloaded constructors
	//default constructor
	Rectangle()
	{
		length = width = 1;
	}
	//parameterized constructor
	Rectangle(int l, int b);

	//facilitators
	void area();
	void perimeter();

	//getters
	int get_length()
	{
		return length;
	}
	int get_width()
	{
		return width;
	}

	//mutators
	void set_length(int l)
	{
		length = l;
	}
	void set_width(int w)
	{
		width = w;
	}

	//desctructor
	~Rectangle();
};

Rectangle::Rectangle(int l, int w)
{
	length = l;
	width = w;
}

void Rectangle::area()
{
	cout << "Area: " << length * width << "\n";
}

void Rectangle::perimeter()
{
	cout << "Perimeter: " << 2 * (length + width) << "\n";
}

Rectangle::~Rectangle()
{
	cout << "Done\n";
}

int main()
{
	Rectangle r;
	r.area();
	r.perimeter();
	r.set_length(3);
	r.area();
	r.perimeter();

	return 0;
}
