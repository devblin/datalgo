#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
	int length, width;
};

void initialize(struct Rectangle *r, int l, int w)
{
	cout << "Initializing: length = " << l << " & width = " << w << "\n";
	r->length = l;
	r->width = w;
}

void area(struct Rectangle r)
{
	cout << "Area of rectangle: " << r.width * r.length << "\n";
}

void changeLength(struct Rectangle *r, int l)
{
	cout << "Changing length to " << l << "\n";
	r->length = l;
}

int main()
{
	struct Rectangle r;
	initialize(&r, 2, 3);
	area(r);
	changeLength(&r, 6);
	area(r);
	return 0;
}
