#include <stdio.h>
#include <stdlib.h>

/*
Structure is user-defined data-type:
1. defining structure
2. size of structure
3. declaring structure
4. accessing members

Example:
Rectangle - length, width

struct of Rectangle => length, width
*/

//defining structure
struct Rectangle // 4 + 4 = 8byte
{
	int length; // 4byte
	int width;	// 4byte
} r1_global;	//other way to declare struct globally

struct Rectangle r2_global; //declaring struct globally

struct Complex
{
	int real;
	int img;
	/*Complex no.: (a + bi);
	a -> real parrt
	b -> imaginary part

	Size of this structure = sizeof(img) + sizeof(real) = 4 + 4 = 9
	*/
};
/*
Declaring the student struct in following way avoids padding of memory instead packing of memory happens:

struct __attribute__((__packed__)) Student {

}
*/
struct Student
{
	int roll;		   //size 4
	char name[30];	   //size 1*30 = 30
	char dept[20];	   //size 1*20 = 20
	char address[100]; //size 1*100 = 100

	/*Size of student structure =  4+30+20+100 = 154 (due to padding of memory allocated size will be 156,
	 													but extra memory allocated wont be used)*/
};

struct RightAngledTriangle
{
	int height; // size 4
	int base;	// size 4

	//Size of this structure = 4+4 = 8
};

struct Card
{
	/*
	CARD:
	face_value = 1,2,3,.....10,J,Q,K
	shape = club-0, spade-1, diamond-3, heart-4
	color = black-0, red-0
	*/
	int face_value; //size 4
	int shape;		//size 4
	int color;		//size 4

	//Size of this structure = 4+4+4 = 12
};

int main()
{
	struct Rectangle r; //decalaration of a data-type Rectangle
	/*
	MAIN MEMORY
	------------------------
	Heap Memory:

	------------------------
	Stack Memory:
	r[length][width]
	r1[10][5]
	------------------------
	Code Section:
	main()

	------------------------
	*/
	struct Rectangle r1 = {10, 5}; //intialization of length and width with datatype Rectangle
	printf("Size of r: %ld\n", sizeof(r));
	printf("r.length: %d\nr.width: %d\n", r.length, r.width); //accessing members
	printf("Size of r1: %ld\n", sizeof(r1));
	printf("r1.length: %d\nr1.width: %d\n", r1.length, r1.width);
	r.length = 99;
	r.width = 9;
	printf("r.length: %d\nr.width: %d\n", r.length, r.width);

	struct Student s[10] = {{1, "Deep", "ICE", "Ghar mei rehta hu"}}; //array of structures, this is like list of 10 students
	/*
	For above Student array of structure, total size = 10*sizeof(struct Student) = 10 * 154 = 1540
	*/
	printf("Size of s: %ld\n", sizeof(s[1]));
	printf("s[0].roll: %d\ns[0].name: %s\ns[0].dept: %s\ns[0].address: %s\n", s[0].roll, s[0].name, s[0].dept, s[0].address);
	return 0;
}
