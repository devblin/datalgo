#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    int *A, size, length = 0;
    Array(int newSize);
    void Display();
    Array *Merge(Array *B);
    Array *Union(Array *B);
    Array *Intersection(Array *B);
    Array *Difference(Array *B);
    ~Array();
};

Array::Array(int newSize)
{
    size = newSize;
    A = new int[newSize];
}

void Array::Display()
{
    int i;
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

Array *Array::Merge(Array *B)
{
    int m = length;
    int n = B->length;
    int i = 0, j = 0, k = 0;
    Array *C;
    C = new Array(size + B->size);

    while (i != m && j != n)
    {
        if (A[i] < B->A[j])
            C->A[k++] = A[i++];
        else if (A[i] > B->A[j])
            C->A[k++] = B->A[j++];
        else if (A[i] == B->A[j])
        {
            C->A[k++] = A[i];
            i++;
            j++;
        }
        C->length++;
    }
    for (; i < m;)
    {
        C->A[k++] = A[i++];
        C->length++;
    }
    for (; j < n;)
    {
        C->A[k++] = B->A[j++];
        C->length++;
    }
    return C;
}

Array::~Array()
{
    delete[] A;
    cout << "Bye-Bye\n";
}

int main()
{
    int i;
    Array *A, *B, *C;
    A = new Array(4);
    B = new Array(5);

    for (i = 0; i < A->size; i++)
    {
        A->A[i] = (2 * i) + 1;
        A->length++;
    }
    for (i = 0; i < B->size; i++)
    {
        B->A[i] = 2 * i;
        B->length++;
    }

    cout << "A: ";
    A->Display();
    cout << "B: ";
    B->Display();

    C = A->Merge(B);
    cout << "C: ";
    C->Display();

    return 0;
}
