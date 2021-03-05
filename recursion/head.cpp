#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
	if (n > 0)
	{
		fun(n - 1);
		cout << n << " ";
	}
	/*
	T(n) = O(n)
	S(n) = O(n)
	*/
}

void fun1(int n)
{
	int i = 1;
	while (i <= n)
	{
		cout << i << " ";
		i++;
	}
	/*
	T(n) = O(n)
	S(n) = O(2) = O(1)
	*/
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