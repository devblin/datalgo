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

int sumLoop(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n--;
	}
	return sum;
}

int main()
{
	int x;
	cin >> x;
	cout << "Sum using recursion: " << sumRecursion(x) << endl;
	cout << "Sum using loop: " << sumLoop(x);

	return 0;
}
