#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

int Area(struct Rectangle r)
{
	return r.width * r.length;
}

int AreaRef(struct Rectangle &r)
{
	r.width++;
	r.length++;
	return r.length * r.width;
}

int main()
{
	struct Rectangle r = {10, 5};
	cout << "r.length: " << r.length << "\nr.width: " << r.width << "\n";
	cout << Area(r) << "\n";
	cout << "Incrementing length & width\n";
	cout << AreaRef(r) << "\n";
	cout << "r.length: " << r.length << "\nr.width: " << r.width << "\n";
}