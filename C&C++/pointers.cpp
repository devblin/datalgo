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

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 10; //data variable
	int *p1;	//pointer variable
	p1 = &a;	//pointer p1 holding address of a
	printf("a: %d\n", a);
	printf("*p1: %d\n", *p1); //dereferncing to get the value of the data variable to which it points
	printf("p1: %p\n", p1);	  //prints address of a cause it points to address of a
	printf("&p1: %p\n", &p1); //prints address of itself
	printf("&a: %p\n", &a);

	printf("------------------\n");
	int *p2;
	p2 = (int *)malloc(3 * sizeof(int)); //allocated memory for 3 int in heap
	printf("p2: %p\n", p2);
	printf("p2[0]: %d\n", p2[0]);
	printf("&p2[0]: %p\n", &p2[0]);
	printf("p2[1]: %d\n", p2[1]);
	printf("&p2[1]: %p\n", &p2[1]);
	printf("p2[1]: %d (using address of p2)\n", *(p2 + 4));
	p2[0] = 123;
	p2[1] = 333;
	printf("p2[0]: %d\n", p2[0]);
	printf("p2[1]: %d\n", p2[1]);

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