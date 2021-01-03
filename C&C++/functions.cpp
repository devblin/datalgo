#include <bits/stdc++.h>
using namespace std;

/*
FUNCTIONS:
Monolithic Programming -> Everthing inside main.
Modular/Procedural Programming -> Program consisting of several functions.
*/

void SwapByAddress(int *a, int *b) //formal pointers points to address passed
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	cout << "Swap by address\n";
}

void SwapByValue(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "Swap by value\n";
}

int add(int a, int b) //prototype of function, a, b are called formal parameters
{
	return (a + b);
}

int main()
{
	int x, y, z;
	cout << "Enter x & y: ";
	cin >> x >> y;
	z = add(x, y); //function call, where x, y are called actual parameters
	cout << "Sum x & y: " << z << "\n";
	cout << "--------------------------------\n";
	/*PARAMETER PASSING
	1. pass by value
	2. pass by address
	3. pass by reference
	*/

	//PASS BY VALUE
	int x1, y1;
	cout << "Enter x1 & y1: ";
	cin >> x1 >> y1;
	SwapByValue(x1, y1);
	cout << "x1: " << x1 << "\ny1: " << y1 << "\n";

	//PASS BY ADDRESS
	SwapByAddress(&x1, &y1); //sending address of the variables
	cout << "x1: " << x1 << "\ny1: " << y1 << "\n";

	return 0;
}