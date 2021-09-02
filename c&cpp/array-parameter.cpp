#include <iostream>
using namespace std;

void Display1(int *A, int n) //array is always passed by address
{
	int i, n;
	cout << "Display1\n";
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
		A[i] = 3;
	}
	cout << "\nReplacing all values by 3\n";
	for (i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

void Display2(int A[], int n)
{
	int i, n;
	cout << "Display2\n";
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
		A[i] = 5;
	}
	cout << "\nReplacing all values by 5\n";
	for (i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

int *ReturnArray(int n)
{
	int *p;
	p = new int[n];
	return p;
}

int main()
{
	int A[3] = {1, 2, 3};
	Display1(A, 3);
	Display2(A, 3);
	int *B;
	B = ReturnArray(4);
	Display1(B, 3);
	delete B;

	return 0;
}