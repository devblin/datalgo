#include <bits/stdc++.h>
using namespace std;

template <class T>
class Heap
{
private:
    T *A;
    int length = 0, size = 0;

public:
    Heap(int size);
    void Insert(T num);
    void Delete();
    void Create(T a[]);
    void Display();
    ~Heap();
};

template <class T>
Heap<T>::Heap(int size)
{
    size = size;
    A = new int[size];
}

//Inserting into heap
template <class T>
void Heap<T>::Insert(T num)
{
    T temp = n;
    int parent, child = length;
    A[length] = num;
    parent = (child % 2 == 0) ? (child - 1) / 2
}

//Creating heap from arrays
template <class T>
void Heap<T>::Create(T a[])
{
}

//Deleting max element from heap
template <class T>
void Heap<T>::Delete()
{
}

//Display heap elements
template <class T>
void Heap<T>::Display()
{
    if (length == 0)
    {
        cout << "Heap Empty\n";
        return;
    }
    int i;
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

template <class T>
Heap<T>::~Heap()
{
    delete[] A;
}

int main()
{
    Heap<int> *a = new Heap<int>(5);
    a->Display();
    a->Insert(35);
    a->Insert(30);
    a->Insert(20);
    a->Insert(40);
    return 0;
}