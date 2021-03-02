#include <bits/stdc++.h>
using namespace std;

int main()
{
	int length = 0, width = 0;
	cout << "Enter length & width: ";
	cin >> length >> width;
	cout << "Area of rectangle: " << length * width << "\n";
	cout << "Perimeter of rectangle: " << 2 * (length + width) << "\n";
	return 0;
}