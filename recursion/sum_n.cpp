#include <bits/stdc++.h>
using namespace std;

int sumRecursion(int n)
{
	if (n > 0)
	{
		return sumRecursion(n - 1) + n;
	}
	return 0;
}
/*
T(n) = O(n)
S(n) = 0(n)
*/

int sumFormula(int n)
{
	return n * (n + 1) / 2;
}
/*
T(n) = O(1)
S(n) = O(1)
*/

int sumLoop(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n--;
	}
	return sum;
}
/*
T(n) = O(n)
S(n) = O(1)
*/

int main()
{
	int x;
	cin >> x;
	cout << "Sum using recursion: " << sumRecursion(x) << endl;
	cout << "Sum using loop: " << sumLoop(x) << endl;
	cout << "Sum using formula: " << sumFormula(x);

	return 0;
}
