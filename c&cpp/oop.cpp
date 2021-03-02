#include <bits/stdc++.h>
using namespace std;

class Rectangle1
{
private:
	int length, width;

public:
	void initialize(int l, int b)
	{
		length = l;
		width = b;
		cout << "Intialized: l = " << l << ", b = " << b << "\n";
	}
	void area()
	{
		cout << "Area: " << length * width << "\n";
	}
	void perimeter()
	{
		cout << "Perimeter: " << 2 * (length + width) << "\n";
	}
};

//all member functions & variables are public
struct Rectangle2
{
	int length, width;

	void initialize(int l, int b)
	{
		length = l;
		width = b;
		cout << "Intialized: l = " << l << ", b = " << b << "\n";
	}
	void area()
	{
		cout << "Area: " << length * width << "\n";
	}
	void perimeter()
	{
		cout << "Perimeter: " << 2 * (length + width) << "\n";
	}
};

int main()
{
	Rectangle1 r1;
	Rectangle2 r2;
	r1.initialize(1, 2);
	r1.area();
	r1.perimeter();
	r2.length = 2, r2.width = 4; //we can't do this for class Rectangle1, since length&width are private member
	r2.area();
	r2.perimeter();
	return 0;
}