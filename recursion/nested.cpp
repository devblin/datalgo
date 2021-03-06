#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
	if (n > 0)
	{
		return fun(fun(n - 10));
	}
	return -1;
}

int fun1(int n)
{
	if (n > 100)
	{
		return n - 10;
	}
	return fun1(fun1(n + 11));
}

int main()
{
	int x;
	cin >> x;
	cout << fun(x);
	cout << "\n";
	cout << fun1(x);

	return 0;
}