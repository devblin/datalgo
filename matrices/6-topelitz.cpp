#include <bits/stdc++.h>
using namespace std;

class Topelitz
{
private:
    int *A, size;

public:
    Topelitz(int size);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    ~Topelitz();
};

Topelitz::Topelitz(int size)
{
    A = new int[2 * size - 1];
    this->size = size;
}

void Topelitz::Set(int i, int j, int value)
{
    if (i == 0 || j == 0)
    {
        if (i <= j)
            A[j] = value;
        else
            A[size - 1 + i] = value;
    }
}

int Topelitz::Get(int i, int j)
{
    if (i <= j)
        return A[j - i];
    return A[size - 1 + (i - j)];
}

void Topelitz::Display()
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            cout << (Get(i, j) <= 9 ? "0" : "") << Get(i, j) << " ";
        cout << "\n";
    }
}

Topelitz::~Topelitz()
{
    delete[] A;
}

int main()
{
    int size = 6, k = 1;
    Topelitz *t = new Topelitz(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            t->Set(i, j, k++);

    t->Display();
    return 0;
}