#include <bits/stdc++.h>
using namespace std;

/*
FUNCTIONS:
Monolithic Programming -> Everthing inside main.
Modular/Procedural Programming -> Program consisting of several functions.
*/

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

	return 0;
}

/*
MAIN MEMORY
----------------------
HEAP
----------------------


----------------------
STACK
----------------------
swapbyvalue: a[10] b[5] => a[5] b[10] (gets deleted after swapping)
add: a[10] b[5]  (gets deleted after return)
main: 
x[10] y[5] z[15] (prints 15)
x1[10] y1[5] (no change in value of x1 & y1 after swapbyvalue)
----------------------
CODE SECTION
----------------------
swapbyvalue()
add()
main()
----------------------
*/