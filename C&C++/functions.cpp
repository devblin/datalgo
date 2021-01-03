#include <bits/stdc++.h>
using namespace std;

/*
FUNCTIONS:
Monolithic Programming -> Everthing inside main.
Modular/Procedural Programming -> Program consisting of several functions.
*/

int add(int a, int b) //prototype of function, a, b are called formal parameters
{
	return (a + b);
}

int main()
{
	int x, y, z;
	x = 10;
	y = 5;
	z = add(x, y); //function call, where x, y are called actual parameters
	cout << "Sum x & y: " << z << "\n";

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
add: a[10] b[5]  (gets deleted after return)
main: x[10] y[5] z[15] (prints 15)
----------------------
CODE SECTION
----------------------
add()
main()

----------------------
*/