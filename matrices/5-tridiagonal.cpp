#include <bits/stdc++.h>
using namespace std;

class TriDiagonal
{
private:
    int *A, size;

public:
    TriDiagonal(int size);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    ~TriDiagonal();
};

TriDiagonal::TriDiagonal(int size)
{
    A = new int[(3 * size) - 2];
    this->size = size;
}

void TriDiagonal::Set(int i, int j, int value)
{
    if (i - j == -1)
        A[i] = value;
    else if (i - j == 0)
        A[size - 1 - i] = value;
    else if (i - j == 1)
        A[2 * size - 1 + j] = value;
}

int TriDiagonal::Get(int i, int j)
{
    if (i - j == -1)
        return A[i];
    else if (i - j == 0)
        return A[size - 1 - i];
    else if (i - j == 1)
        return A[2 * size - 1 + j];
    return 0;
}

void TriDiagonal::Display()
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

TriDiagonal::~TriDiagonal()
{
    delete[] A;
}

int main()
{
    int size = 3, k = 1;
    TriDiagonal *tri = new TriDiagonal(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            tri->Set(i, j, k++);
    tri->Display();
    return 0;
}