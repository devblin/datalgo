#include <bits/stdc++.h>
using namespace std;

class UpperTriangleRow
{
private:
    int *A;
    int size;

public:
    UpperTriangleRow(int size);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    ~UpperTriangleRow();
};

UpperTriangleRow::UpperTriangleRow(int size)
{
    A = new int[(size * (size + 1) / 2)];
    this->size = size;
}

void UpperTriangleRow::Set(int i, int j, int value)
{
    int index = ((size * (size + 1) / 2) - ((size - i) * (size - i + 1) / 2) + (j - i));
    if (i <= j)
        A[index] = value;
}

int UpperTriangleRow::Get(int i, int j)
{
    int index = ((size * (size + 1) / 2) - ((size - i) * (size - i + 1) / 2) + (j - i));
    if (i <= j)
        return A[index];
    return 0;
}

void UpperTriangleRow::Display()
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

UpperTriangleRow::~UpperTriangleRow()
{
    delete[] A;
}

class UpperTriangleCol
{
private:
    int *A, size;

public:
    UpperTriangleCol(int size);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    ~UpperTriangleCol();
};

UpperTriangleCol::UpperTriangleCol(int size)
{
    A = new int[(size * (size + 1)) / 2];
    this->size = size;
}

void UpperTriangleCol::Set(int i, int j, int value)
{
    int index = ((j * (j + 1) / 2) + i);
    if (i <= j)
        A[index] = value;
}

int UpperTriangleCol::Get(int i, int j)
{
    int index = ((j * (j + 1) / 2) + i);
    if (i <= j)
        return A[index];
    return 0;
}

void UpperTriangleCol::Display()
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

UpperTriangleCol::~UpperTriangleCol()
{
    delete[] A;
}

int main()
{
    int size = 4, k = 1;
    UpperTriangleRow *row = new UpperTriangleRow(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            row->Set(i, j, k++);
    k = 1;
    row->Display();
    cout << "\n";
    UpperTriangleCol *col = new UpperTriangleCol(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            col->Set(i, j, k++);
    col->Display();

    return 0;
}