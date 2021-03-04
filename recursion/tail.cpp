#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		fun(n - 1); //calling itself at the end, and doesn't perform anything at return time
	}
	/*
	T(n) = O(n)
	S(n) = O(n)
	*/
}

void fun2(int n)
{
	while (n > 0)
	{
		cout << n << " ";
		n--;
	}
	//T(n) = O(n), S(n) = O(1)
}

int fun1(int n)
{
	if (n > 0)
	{
		return fun1(n - 1) + n; //calling at end, but 'n' will be added only while returning, so not a tail recursion
	}
	return 0;
}

int main()
{
	int x;
	cin >> x;
	fun(x);
	fun2(x);
}