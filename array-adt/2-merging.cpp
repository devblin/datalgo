#include <bits/stdc++.h>
using namespace std;

template <class T>
class Array
{
public:
    T *A;
    int size, length = 0;
    Array(int newSize);
    void Display();
    Array *Merge(Array *B);
    Array *UnionUnsorted(Array *B);
    Array *UnionSorted(Array *B);
    Array *IntersectionUnsorted(Array *B);
    Array *IntersectionSorted(Array *B);
    Array *DifferenceUnsorted(Array *B);
    Array *DifferenceSorted(Array *B);
    ~Array();
};

template <class T>
bool isInArray(Array<T> *B, T key)
{
    int i, m = B->length;
    for (i = 0; i < m; i++)
        if (B->A[i] == key)
            return true;
    return false;
}

template <class T>
Array<T>::Array(int newSize)
{
    size = newSize;
    A = new T[newSize];
}

template <class T>
void Array<T>::Display()
{
    int i;
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

template <class T>
Array<T> *Array<T>::Merge(Array *B)
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
            C->A[k++] = A[i];
            i++;
            j++;
            C->length++;
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

template <class T>
Array<T> *Array<T>::UnionUnsorted(Array *B)
{
    int m = length, n = B->length, i, j;
    Array *C;
    C = new Array(m + n);

    //Copy A to C;
    for (i = 0; i < m; i++)
        C->A[i] = A[i];

    C->length = m;
    for (i = 0; i < n; i++)
    {
        if (!isInArray(C, B->A[i]))
        {
            C->A[m++] = B->A[i];
            C->length++;
        }
    }

    return C;
}

template <class T>
Array<T> *Array<T>::UnionSorted(Array *B)
{
    int m = length, n = B->length, i = 0, j = 0, k = 0;
    Array *C;
    C = new Array(m + n);

    while (i < m && j < n)
    {
        if (A[i] < B->A[j])
            C->A[k++] = A[i++];
        else if (A[i] > B->A[j])
            C->A[k++] = B->A[j++];
        else if (A[i] == B->A[j])
        {
            C->A[k++] = A[i++];
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

template <class T>
Array<T> *Array<T>::IntersectionUnsorted(Array *B)
{
    Array *C;
    int i;
    int m = length, n = B->length;
    C = new Array(m + n);
    for (i = 0; i < m; i++)
        if (isInArray(B, A[i]))
            C->A[C->length++] = A[i];

    return C;
}

template <class T>
Array<T> *Array<T>::IntersectionSorted(Array *B)
{
    Array *C;
    int i = 0, j = 0, m = length, n = B->length;
    C = new Array(m + n);
    while (i < m && j < n)
    {
        if (A[i] < B->A[j])
            i++;
        else if (A[i] > B->A[j])
            j++;
        else if (A[i] == B->A[j])
        {
            C->A[C->length++] = A[i++];
            j++;
        }
    }
    return C;
}

template <class T>
Array<T> *Array<T>::DifferenceUnsorted(Array *B)
{
    Array *C;
    int i, m = length, n = B->length;
    C = new Array(m + n);
    for (i = 0; i < m; i++)
        if (!isInArray(B, A[i]))
            C->A[C->length++] = A[i];
    for (; i < m;)
        C->A[C->length++] = A[i++];
    return C;
}

template <class T>
Array<T> *Array<T>::DifferenceSorted(Array *B)
{
    Array *C;
    int i = 0, j = 0, m = length, n = B->length;
    C = new Array(m + n);
    while (i < m && j < n)
    {
        if (A[i] < B->A[j])
            C->A[C->length++] = A[i++];
        else if (A[i] > B->A[j])
            j++;
        else if (A[i] == B->A[j])
        {
            i++;
            j++;
        }
    }
    for (; i < m;)
        C->A[C->length++] = A[i++];

    return C;
}

template <class T>
Array<T>::~Array()
{
    delete[] A;
    cout << "Bye-Bye\n";
}

template <class T>
void menu(Array<T> *A, Array<T> *B)
{
    int i, option;
    cout << "Enter elements for A: ";
    A->length = 0;
    B->length = 0;
    for (i = 0; i < A->size; i++)
    {
        cin >> A->A[i];
        A->length++;
    }
    cout << "Enter elements for B: ";
    for (i = 0; i < B->size; i++)
    {
        cin >> B->A[i];
        B->length++;
    }
    cout << "A: ";
    A->Display();
    cout << "B: ";
    B->Display();
    cout << "1. Merge\n";
    cout << "2. UnionUnsorted\n";
    cout << "3. UnionSorted\n";
    cout << "4. IntersectionUnsorted\n";
    cout << "5. IntersectionSorted\n";
    cout << "6. DifferenceUnsorted\n";
    cout << "7. DifferenceSorted\n";
    cout << "0. Exit\n";
    cout << "Enter option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "Merging A and B: ";
        A->Merge(B)->Display();
        break;
    case 2:
        cout << "UnionUnsorted of A and B: ";
        A->UnionUnsorted(B)->Display();
        break;
    case 3:
        cout << "UnionSorted of A and B: ";
        A->UnionSorted(B)->Display();
        break;
    case 4:
        cout << "IntersectionUnsorted of A and B: ";
        A->IntersectionUnsorted(B)->Display();
        break;
    case 5:
        cout << "IntersectionSorted of A and B: ";
        A->IntersectionSorted(B)->Display();
        break;
    case 6:
        cout << "DifferenceUnsorted of A and B: ";
        A->DifferenceUnsorted(B)->Display();
        break;
    case 7:
        cout << "DifferenceSorted of A and B: ";
        A->DifferenceSorted(B)->Display();
        break;
    default:
        break;
    }
    if (option != 0)
        menu(A, B);
}

int main()
{
    int i;
    Array<float> A(4), B(5);
    menu(&A, &B);
    return 0;
}
