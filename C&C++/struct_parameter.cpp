#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

int Area(struct Rectangle r)
{
	cout << "Area: ";
	return r.width * r.length;
}

int AreaRef(struct Rectangle &r)
{
	r.width++;
	r.length++;
	cout << "AreaRef: ";
	return r.length * r.width;
}

void ChangeLength(struct Rectangle *r, int x)
{
	cout << "Changing length to " << x << "\n";
	r->length = x;
}

void ChangeWidth(struct Rectangle *r, int x)
{
	cout << "Changing width to " << x << "\n";
	r->width = x;
}

int main()
{
	struct Rectangle r = {10, 5};
	cout << "r.length: " << r.length << "\nr.width: " << r.width << "\n";
	cout << Area(r) << "\n";
	cout << "Incrementing length & width\n";
	cout << AreaRef(r) << "\n";
	cout << "r.length: " << r.length << "\nr.width: " << r.width << "\n";
	ChangeLength(&r, 12);
	cout << Area(r) << "\n";
	ChangeWidth(&r, 12);
	cout << Area(r) << "\n";
}