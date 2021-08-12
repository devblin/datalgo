#include "../trees/tree.h"

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int childIndex(int *A, int parent, bool isMaxHeap)
{
    if (isMaxHeap)
        return A[2 * parent + 1] > A[2 * parent + 2] ? 2 * parent + 1 : 2 * parent + 2;
    return A[2 * parent + 1] < A[2 * parent + 2] ? 2 * parent + 1 : 2 * parent + 2;
}

bool heapCompare(int a, int b, bool isMaxHeap)
{
    if (isMaxHeap)
        return a < b;
    return a > b;
}

void heapify(int *A, int n, bool isMaxHeap = true)
{
    int i = 0, parent, child;
    for (i = n - 1; i >= 0; i--)
    {
        parent = i;
        child = childIndex(A, parent, isMaxHeap);
        if (child < n)
            while (heapCompare(A[parent], A[child], isMaxHeap))
            {
                swap(A[parent], A[child]);
                parent = child;
                child = childIndex(A, parent, isMaxHeap);
                if (child >= n)
                    break;
            }
    }
}

int main()
{
    int A[7] = {5, 10, 30, 20, 35, 40, 15};
    Tree *h = new Tree();
    heapify(A, 7, false); //false - min heap, true - max heap
    h->create(A, 7);
    h->levelorder();

    return 0;
}