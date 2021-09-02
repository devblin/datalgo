#include <iostream>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

int main()
{
	int a = 10, b = 25;
	int &r = a; //reference r is 'a' only
	/*
	Reference act as an alias for any data variable to which it has been assigned.
	Reference needs to be always intiazlied while declaring becoz we cant give an alias to 
	unknown variable.
	*/
	cout << "a: " << a << "\n";
	cout << "&a: " << &a << "\n";
	cout << "r: " << r << "\n";
	cout << "&r: " << &r << "\n";
	cout << "r = 5\n";
	r = 5;
	cout << "a: " << a << "\n";
	cout << "r: " << r << "\n";
	cout << "--------------------\n";

	struct Rectangle rect = {10, 15};
	struct Rectangle &ref_rect = rect;
	cout << "&rect: " << &rect << "\n";
	cout << "&ref_rect: " << &ref_rect << "\n";
	cout << "rect.length: " << rect.length << "\n";
	cout << "ref_rect.length: " << ref_rect.length << "\n";
	cout << "ref_rect.length = 23\n";
	ref_rect.length = 23;
	cout << "rect.length: " << rect.length << "\n";
	cout << "ref_rect.length: " << ref_rect.length << "\n";

	return 0;
}

/*
MAIN MEMORY
------------------------
Heap Memory:

------------------------
Stack Memory:
	a[10]
------------------------
Code Section:
main()

------------------------
*/