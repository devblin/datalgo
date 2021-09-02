#include <iostream>
using namespace std;

int main()
{
	int a;	//normal variable
	int *p; //pointer variable
	/*
	memory is allocated in stack for normal and pointer variables
	*/
	p = new int[5]; //dynamically allocated memory for 5 integers, which can be accessed by pointer variable

	delete[] p; //deallocating memory
	p = NULL;	//pointing pointer to nothing
	return 0;
}