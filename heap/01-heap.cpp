#include <bits/stdc++.h>
using namespace std;

//Min and Max heap, also used for priority queue
class Heap
{
private:
    vector<int> *A;
    int size = 0;
    bool isMaxHeap;

public:
    Heap(bool isMaxHeap);
    void insert(int data);
    void create(int B[], int n);
    bool heapCompare(int a, int b)
    {
        if (isMaxHeap)
            return a > b;
        else
            return a < b;
    }
    int remove();
    void heapSort();
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void display();
};

Heap::Heap(bool isMaxHeap)
{
    A = new vector<int>;
    this->isMaxHeap = isMaxHeap;
}

void Heap::insert(int data)
{
    int child, parent;
    A->push_back(data);
    size++;
    child = size - 1;
    parent = child % 2 == 0 ? (child - 2) / 2 : (child - 1) / 2;
    if (parent < 0 || child < 0)
        return;
    while (heapCompare((*A)[child], (*A)[parent]))
    {
        swap((*A)[child], (*A)[parent]);
        child = parent;
        parent = child % 2 == 0 ? (child - 2) / 2 : (child - 1) / 2;
        if (parent < 0 || child < 0)
            return;
    }
}

void Heap::create(int B[], int n)
{
    for (int i = 0; i < n; i++)
        insert(B[i]);
    display();
}

void Heap::heapSort()
{
    vector<int> *heap = new vector<int>;
    while (!A->empty())
        heap->push_back(remove());
    A = heap;
    size = heap->size();
    display();
}

int Heap::remove()
{
    int deleted = (*A)[0], parent, child, i;
    (*A)[0] = (*A)[--size];
    A->pop_back();
    parent = 0;
    i = 2 * parent + 1;
    child = heapCompare((*A)[i], (*A)[i + 1]) ? i : i + 1;
    while (!heapCompare((*A)[parent], (*A)[child]))
    {
        swap((*A)[parent], (*A)[child]);
        parent = child;
        i = 2 * parent + 1;
        if (i + 1 <= size)
            child = heapCompare((*A)[i], (*A)[i + 1]) ? i : i + 1;
        else
            return deleted;
    }
    return deleted;
}

void Heap::display()
{
    int i;
    for (i = 0; i < size; i++)
        cout << (*A)[i] << " ";
    cout << "\n";
}

int main()
{
    Heap *max = new Heap(true);
    Heap *min = new Heap(false);
    int size = 7, A[size] = {10, 20, 30, 25, 5, 40, 35};

    cout << "Max heap:\n";
    max->create(A, size);
    cout << max->remove() << "\n";
    max->display();
    max->heapSort();

    cout << "Min heap:\n";
    min->create(A, size);
    cout << min->remove() << "\n";
    min->display();
    min->heapSort();

    delete max, min;

    return 0;
}
