#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

int main()
{
	struct Rectangle r = {1, 2};
	struct Rectangle *p;
	p = &r;
	cout << "size of r: " << sizeof(r) << "\n";
	cout << "size of p: " << sizeof(p) << "\n";
	cout << "r.length: " << r.length << "\n";
	cout << "p.length: " << p->length << "\n";
	cout << "(*p).length = 66\n";
	(*p).length = 66;
	cout << "r.length: " << r.length << "\n";
	cout << "(*p).length: " << (*p).length << "\n";
	cout << "p->length = 99\n";
	p->length = 99;
	cout << "r.length: " << r.length << "\n";
	cout << "p->length: " << p->length << "\n";
	cout << "-------------------------\n";

	struct Rectangle *p1;
	p1 = new Rectangle;
	cout << "&p1: " << &p1 << "\n";
	cout << "&p1->length: " << &p1->length << "\n";
	cout << "p1->length: " << p1->length << "\n";
	cout << "p1->length = 33\n";
	p1->length = 33;
	cout << "p1->length: " << p1->length << "\n";
	delete p1;

	return 0;
}

/*
MAIN MEMORY
------------------------
Heap Memory:

------------------------
Stack Memory:

------------------------
Code Section:
main()

------------------------
*/