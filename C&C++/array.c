#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A[4];
	int B[3] = {1, 2, 3};
	/*
	MAIN MEMORY
	------------------------
	Heap Memory:



	------------------------
	Stack Memory:
	(Array will be created here)
	A[34][23][53][2] (with garbage values)
	B[1][2][3] (array intialized with values)

	[23][434][2323] -> contiguous block of memory

	------------------------
	Code Section:
	main()




	------------------------
	*/
	printf("Size of A: %ld\n", sizeof(A));
	printf("Size of B: %ld\n", sizeof(B));
	printf("%d %d\n", A[0], A[1]);

	int i;
	for (i = 0; i < 3; i++)
	{
		printf("%d ", B[i]);
	}
	printf("\n");

	i = 0;
	while (i < 3)
	{
		printf("%d ", B[i++]);
	}
	printf("\n");

	i = 0;
	do
	{
		printf("%d ", B[i++]);
	} while (i < 3);
	printf("\n");

	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int C[n];
	i = 0;
	while (i < n)
	{
		printf("%d ", C[i++]);
	}
	printf("\n");
	return 0;
}