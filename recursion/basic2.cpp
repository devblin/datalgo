#include <bits/stdc++.h>
using namespace std;

void fun1(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		fun1(n - 1);
	}
}

void fun2(int n)
{
	if (n > 0)
	{
		fun2(n - 1);
		cout << n << " ";
	}
}

int main()
{
	int x;
	cin >> x;
	fun1(x);
	cout << endl;
	fun2(x);
	return 0;
}