#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//generic class using template
template <class T>
class Arithmatic
{
private:
	T a, b;

public:
	Arithmatic()
	{
		a = b = 1;
	}
	Arithmatic(T a, T b);
	void add();
	void multiply();
	void substract();
	void divide();
	~Arithmatic();
};

template <class T>
Arithmatic<T>::Arithmatic(T a, T b)
{
	this->a = a;
	this->b = b;
}

template <class T>
void Arithmatic<T>::add()
{
	cout << "Adding " << a << ", " << b << " = " << a + b << "\n";
}

template <class T>
void Arithmatic<T>::substract()
{
	cout << "Substracting " << a << ", " << b << " = " << a - b << "\n";
}

template <class T>
void Arithmatic<T>::multiply()
{
	cout << "Multiplying " << a << ", " << b << " = " << a * b << "\n";
}

template <class T>
void Arithmatic<T>::divide()
{
	cout << "Dividing " << a << ", " << b << " = " << a / b << "\n";
}

template <class T>
Arithmatic<T>::~Arithmatic()
{
	cout << "Done\n";
}

int main()
{
	float x, y;
	cout << "Enter a & b: ";
	cin >> x >> y;
	Arithmatic<float> a(x, y);
	a.add();
	a.substract();
	a.multiply();
	a.divide();
	return 0;
}
