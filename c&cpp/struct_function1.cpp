#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
	int length, width;
};

void intialize(struct Rectangle *r, int l, int b)
{
	r->length = l;
	r->width = b;
	cout << "Intialized: l = " << l << ", b = " << b << "\n";
}

void area(struct Rectangle r)
{
	cout << "Area of rectangle: " << r.length * r.width << "\n";
}

void perimeter(struct Rectangle r)
{
	cout << "Perimeter of rectangle: " << 2 * (r.width + r.length) << "\n";
}

int main()
{
	Rectangle r = {0, 0};
	cout << "Enter length & width: ";
	cin >> r.length >> r.width;
	intialize(&r, r.length, r.width);
	area(r);
	perimeter(r);
	return 0;
}