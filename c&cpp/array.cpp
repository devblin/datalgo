#include <bits/stdc++.h>
using namespace std;

int main()
{
	/*
	ARRAY:
	A[3]
	
	A[ ][ ][ ] <- array memory blocks
	  0  1  2 <- index
	*/
	int A[4];
	int B[3] = {55, 2, 5};
	/*
	MAIN MEMORY
	------------------
	Heap Memory




	------------------
	Stack Memory
	A[32][-23][-999][0] (fixed memory is allocated in stack for array 
						which are contigous blocks of memory with some 
						garbage values since no intialization done here)
	B[55][2][5] (this array has been intialized with some values)

	[3][4][5] -> contigouos block of memory
	------------------
	Code Section
	main() 


	------------------
	*/
	cout << "Size of A: " << sizeof(A) << "\nSize of B: " << sizeof(B) << '\n';
	cout << A[0] << " " << A[1] << "\n";

	int i;
	for (i = 0; i < 3; i++)
	{
		cout << B[i] << " ";
	}
	cout << "\n";

	i = 0;
	while (i < 3)
	{
		cout << B[i++] << " ";
	}
	cout << "\n";

	i = 0;
	do
	{
		cout << B[i++] << " ";
	} while (i < 3);
	cout << "\n";

	for (auto x : B)
	{
		cout << x << " ";
	}
	cout << "\n";

	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int C[n];
	for (auto x : C)
	{
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}