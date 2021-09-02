/*
POINTERS:
1. declartion
2. intialization
3. dereferencing
4. dynamic allocation

USE OF POINTERS:
1. accessing heap memory, resources.
2. parameter passing
*/
#include <iostream>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

int main()
{
	int a = 10; //data variable
	int *p1;	//pointer variable
	p1 = &a;	//pointer p1 holding address of a
	cout << "a: " << a << "\n";
	cout << "*p1: " << *p1 << "\n"; //dereferncing to get the value of the data variable to which it points
	cout << "p1: " << p1 << "\n";	//prints address of a cause it points to address of a
	cout << "&p1: " << &p1 << "\n"; //prints address of itself
	cout << "&a: " << &a << "\n";
	cout << "----------------------\n";
	int *p2;
	p2 = (int *)malloc(3 * sizeof(int)); //allocated memory for 3 int in heap
	cout << "p2: " << p2 << "\n";
	cout << "p2[0]: " << p2[0] << "\n";
	cout << "&p2[0]: " << &p2[0] << "\n";
	cout << "p2[1]: " << p2[1] << "\n";
	cout << "&p2[1]: " << &p2[1] << "\n";
	cout << "p2[1]: " << *(p2 + 4) << " (using address of p2)\n";
	p2[0] = 123;
	p2[1] = 333;
	cout << "p2[0]: " << p2[0] << "\n";
	cout << "p2[1]: " << p2[1];
	delete p2;
	cout << "\n----------------------";

	int q1[3] = {1, 2, 3};
	int *p3, *p4;
	p3 = q1;
	p4 = &q1[0];
	cout << "\nq1: " << q1;
	cout << "\n&q1[0]: " << &q1[0];
	cout << "\np3: " << p3;
	cout << "\np4: " << p4;
	cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		cout << *(p3 + i) << " ";
	}
	cout << '\n';
	for (int i = 0; i < 3; i++)
	{
		cout << *(p4 + i) << " ";
	}
	cout << "\np4[0]: " << p4[0];
	cout << "\nq1[0]: " << q1[0];
	p4[0] = 111;
	cout << "\np4[0]: " << p4[0];
	cout << "\nq1[0]: " << q1[0];
	cout << "\n----------------------";

	int *q2;
	q2 = new int[3];
	cout << "\n&q2: " << &q2;
	cout << "\nq2: " << q2;
	cout << "\n&q2[0]: " << &q2[0];
	cout << "\nq2[0]: " << q2[0];
	q2[0] = 233;
	q2[1] = 9;
	q2[2] = 999;
	cout << "\nq2[0]: " << q2[0];
	cout << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		cout << q2[i] << " ";
	}
	cout << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		cout << *(q2 + i) << " ";
	}
	delete[] q2;
	cout << "\n----------------------";

	int *w1;
	char *w2;
	float *w3;
	double *w4;
	struct Rectangle *w5;
	cout << "\nsize of int: " << sizeof(w1);			  //expected 4
	cout << "\nsize of char: " << sizeof(w2);			  //expected 1
	cout << "\nsize of float: " << sizeof(w3);			  //expected 4
	cout << "\nsize of double: " << sizeof(w4);			  //expected 8
	cout << "\nsize of struct Rectangle: " << sizeof(w5); //expected 8
	/*
	For each pointer of different data-type we get their size as 8 byte,
	because pointers store the address value of a variable and that address is just an integer,
	hence size of pointer for any variable is 8 byte
	*/
	return 0;
}

/*
MAIN MEMORY
------------------------
Heap Memory:

------------------------
Stack Memory:
a[10] <- p1[ADDRESS OF a]

------------------------
Code Section:
main()

------------------------
*/