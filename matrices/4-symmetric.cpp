#include <bits/stdc++.h>
using namespace std;

class Symmetric
{
private:
    int *A, size;

public:
    Symmetric(int size);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    ~Symmetric();
};

Symmetric::Symmetric(int size)
{
    A = new int[(size * (size + 1)) / 2];
    this->size = size;
}

void Symmetric::Set(int i, int j, int value)
{
    int index = (i * (i + 1) / 2) + j;
    if (i >= j)
        A[index] = value;
}

int Symmetric::Get(int i, int j)
{
    int index = (i >= j) ? (i * (i + 1) / 2) + j : (j * (j + 1) / 2) + i;
    return A[index];
}

void Symmetric::Display()
{
    int i, j, x;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            x = Get(i, j);
            if (x <= 9)
                cout << "0" << x << " ";
            else
                cout << x << " ";
        }
        cout << "\n";
    }
}

Symmetric::~Symmetric()
{
    delete[] A;
}

int main()
{
    int size = 4, k = 1;
    Symmetric *sym = new Symmetric(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            sym->Set(i, j, k++);
    sym->Display();
    return 0;
}