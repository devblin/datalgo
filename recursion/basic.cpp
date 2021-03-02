#include <bits/stdc++.h>
using namespace std;

void fun1(char x)
{
	int n = 0;
	while (n < 10)
	{
		cout << x;
		n++;
		if (n < 10)
			cout << ", ";
	}
	cout << endl;
}

int main()
{
	char x;
	cin >> x;
	fun1(x);
	return 0;
}