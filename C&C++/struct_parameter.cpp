#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

struct Test
{
	int A[3];
	int n;
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

void DisplayTest(struct Test t)
{
	int i;
	cout << "A: { ";
	for (i = 0; i < t.n; i++)
	{
		cout << t.A[i];
		if (i != (t.n) - 1)
		{
			cout << ", ";
		}
	}
	cout << " }\n";
}

int main()
{
	struct Rectangle r = {10, 5};
	cout << "r = {" << r.length << ", " << r.width << "}\n";
	cout << Area(r) << "\n";
	cout << "Incrementing length & width\n";
	cout << AreaRef(r) << "\n";
	cout << "r = {" << r.length << ", " << r.width << "}\n";
	ChangeLength(&r, 12);
	cout << Area(r) << "\n";
	ChangeWidth(&r, 12);
	cout << Area(r) << "\n";

	struct Test t = {{1, 2, 3}, 3};
	DisplayTest(t);
	return 0;
}