#include <bits/stdc++.h>
using namespace std;

/*
Structure is user-defined datatype:
1. defining structure
2. size of structure
3. declaring structure
4. accessing members of structure

Example:-

structure of rectangle consist of length, width
Rectangle members -> length, width
*/

//defining structure
struct Rectangle
{
	int length; //size 4
	int width;	//size 4

	//total size = 4+4 = 8;
} rg = {99, 88}; //declaring global struct variable with intialization

struct Student
{
	int roll;		  //size 4
	char name[25];	  //size 1*25 = 25
	char address[50]; //size 1*50 = 50

	//total size = 4+25+50 = 79
};

/*
Declaring the student struct in following way avoids padding of memory instead packing of memory happens:

struct __attribute__((__packed__)) Student {

}
*/
struct __attribute__((__packed__)) Student2
{
	int roll;		  //size 4
	char name[25];	  //size 1*25 = 25
	char address[50]; //size 1*50 = 50

	//total size = 4+25+50 = 79
};

int main()
{
	struct Rectangle r;			  //declaring r as Rectangle struct
	struct Rectangle r1 = {1, 2}; //deckaring r1 as Rectangle struct and initializing
	cout << "Size of r: " << sizeof(r) << "\n";
	cout << "r.length: " << r.length << "\nr.width: " << r.width << "\n";
	cout << "r1.length: " << r1.length << "\nr1.width: " << r1.width << "\n";

	//global variable output
	cout << "rg.length: " << rg.length << "\nrg.width: " << rg.width << "\n";

	struct Student s;
	cout << "Size of s: " << sizeof(s) << "\n"; //expected 79, but we get 80

	struct Student2 s1;
	cout << "Size of s (without padding): " << sizeof(s1) << "\n"; //we will get 79, bcoz we avoid the padding of memory
	return 0;
}

/*
MAIN MEMORY
------------------------
Heap Memory:

------------------------
Stack Memory:
	r[length][width]
	r1[1][2]

------------------------
Code Section:
	main()

------------------------
Intialized Segment (for global and static variables)	
	rg[99][88]
*/