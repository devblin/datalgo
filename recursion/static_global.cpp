#include <bits/stdc++.h>
using namespace std;

int fun1(int n)
{
	if (n > 0)
	{
		return fun1(n - 1) + n;
	}
	return 0;
}

int fun2(int n)
{
	static int m = 0;
	if (n > 0)
	{
		m++;
		return fun2(n - 1) + m;
	}
	return 0;
}

int y = 0;
int fun3(int n)
{
	if (n > 0)
	{
		y++;
		return fun3(n - 1) + y;
	}
	return 0;
}

int fun4(int n)
{
	int m = 0;
	if (n > 0)
	{
		m++;
		return fun4(n - 1) + m;
	}
	return 0;
}

int main()
{
	int x;
	cin >> x;
	cout << "fun1: " << fun1(x) << "\n";
	cout << "fun2: " << fun2(x) << "\n";
	cout << "fun3: " << fun3(x) << "\n";
	cout << "fun4: " << fun4(x) << "\n";
}