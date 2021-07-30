#include <bits/stdc++.h>
using namespace std;

//LOWER TRIANGLE MATRIX - ROW MAJOR
class LowerTriangleRow
{
private:
    int *A;
    int size;

public:
    LowerTriangleRow(int dimension);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    ~LowerTriangleRow();
};

LowerTriangleRow::LowerTriangleRow(int n)
{
    size = n;
    A = new int[n * (n + 1) / 2];
}

void LowerTriangleRow::Set(int i, int j, int value)
{
    int index = (i * (i + 1) / 2) + j;
    if (i >= j)
        A[index] = value;
}

int LowerTriangleRow::Get(int i, int j)
{
    int index = (i * (i + 1) / 2) + j;
    if (i >= j)
        return A[index];
    return 0;
}

void LowerTriangleRow::Display()
{
    int i, j, r;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            r = Get(i, j);
            if (r > 9)
                cout << r << " ";
            else
                cout << "0" << r << " ";
        }
        cout << "\n";
    }
}

LowerTriangleRow::~LowerTriangleRow()
{
    delete[] A;
}

//LOWER TRIANGLE MATRIX - COLUMN MAJOR
class LowerTriangleCol
{
private:
    int *A;
    int size;

public:
    LowerTriangleCol(int dimension);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void Display();
    ~LowerTriangleCol();
};

LowerTriangleCol::LowerTriangleCol(int n)
{
    size = n;
    A = new int[(n * (n + 1)) / 2];
}

void LowerTriangleCol::Set(int i, int j, int value)
{
    int index = ((size * (size + 1) / 2) - ((size - j) * (size - j + 1) / 2) + (i - j));
    if (i >= j)
        A[index] = value;
}

int LowerTriangleCol::Get(int i, int j)
{
    int index = ((size * (size + 1) / 2) - ((size - j) * (size - j + 1) / 2) + (i - j));
    if (i >= j)
        return A[index];
    return 0;
}

void LowerTriangleCol::Display()
{
    int i, j, r;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            r = Get(i, j);
            if (r > 9)
                cout << r << " ";
            else
                cout << "0" << r << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int size = 9;
    LowerTriangleRow *row = new LowerTriangleRow(size);
    int k = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            row->Set(i, j, k);
            k++;
        }
    }
    row->Display();
    cout << "\n";
    LowerTriangleCol *col = new LowerTriangleCol(size);
    k = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            col->Set(i, j, k);
            k++;
        }
    }
    col->Display();
    return 0;
}