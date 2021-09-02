#include <iostream>
using namespace std;

void area(int l, int b)
{
	cout << "Area of rectangle: " << l * b << "\n";
}

void perimeter(int l, int b)
{
	cout << "Perimeter of rectangle: " << 2 * (l + b) << "\n";
}

int main()
{
	int l = 0, b = 0;
	area(l, b);
	perimeter(l, b);
	cout << "Enter length & width: ";
	cin >> l >> b;
	area(l, b);
	perimeter(l, b);
	return 0;
}