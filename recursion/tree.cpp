#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		fun(n - 1);
		fun(n - 1);
	}
}

void fun1(int n)
{
	if (n > 0)
	{
		fun1(n - 1);
		cout << n << " ";
		fun1(n - 1);
	}
}

int main()
{
	int x;
	cin >> x;
	fun(x);
	cout << "\n";
	fun1(x);
	return 0;
}