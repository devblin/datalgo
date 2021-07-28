#include <bits/stdc++.h>
using namespace std;

class Diagonal
{
private:
    int *A, limit = 0;

public:
    Diagonal(int size);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    ~Diagonal();
};

Diagonal::Diagonal(int size)
{
    A = new int[size];
    limit = size;
}

void Diagonal::Set(int i, int j, int value)
{
    if (i == j && i < limit)
    {
        A[i - 1] = value;
    }
}

int Diagonal::Get(int i, int j)
{
    if (i == j && i < limit)
    {
        return A[i - 1];
    }
    return 0;
}

Diagonal::~Diagonal()
{
    delete[] A;
}

int main()
{
    Diagonal *diag = new Diagonal(5);
    diag->Set(1, 1, 3);
    cout << diag->Get(1, 1);
    return 0;
}