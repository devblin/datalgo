#include <bits/stdc++.h>
using namespace std;

string INVALID_INDEX = "Array full or Invalid index",
       EMPTY_ARRAY = "Array empty",
       FULL_ARRAY = "Array full",
       ENTER_INDEX = "Enter index: ",
       ENTER_VALUE = "Enter value: ",
       ENTER_INDEX_VALUE = "Enter index & value: ";

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

class Array
{
public:
    int *A;
    int size;
    int length;

    Array(int newSize);
    void Display();
    void Append(int value);
    void Insert(int index, int value);
    void Delete(int index);
    int LinearSearch(int key);
    int LinearSearchTransposition(int key);
    int LinearSearchMoveToHead(int key);
    int BinarySearchI(int low, int high, int key);
    int BinarySearchR(int low, int high, int key);
    int Get(int index);
    void Set(int index, int value);
    int Max();
    int Min();
    int SumI();
    int SumR(int n);
    int Avg();
    void Reverse();
    void Rotate(int times);
    ~Array();
};

Array::Array(int newSize)
{
    size = newSize;
    A = new int[size];
    length = 0;
}

void Array::Display()
{
    int i;
    cout << "Array: ";
    if (length > 0)
        for (i = 0; i < length; i++)
            cout << A[i] << " ";
    else
        cout << EMPTY_ARRAY;
    cout << "\n";
}

void Array::Append(int value)
{
    if (length < size)
    {
        A[length] = value;
        cout << "Appended " << value << "\n";
        length++;
    }
    else
        cout << FULL_ARRAY;

    Display();
    cout << "\n";
}

void Array::Insert(int index, int value)
{
    int i;
    if (length < size && index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[i] = value;
        length++;
        cout << "Inserted " << value << " at " << index << "\n";
    }
    else
        cout << INVALID_INDEX;

    Display();
    cout << "\n";
}

void Array::Delete(int index)
{
    int i, deletedVal;
    if (length > 0 && index < length && index >= 0)
    {
        deletedVal = A[index];
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        cout << "Deleted " << deletedVal << "\n";
    }
    else
        cout << INVALID_INDEX;

    Display();
    cout << "\n";
}

int Array::LinearSearch(int key)
{
    int i;
    for (i = 0; i < length; i++)
        if (A[i] == key)
            return i;
    return -1;
}

int Array::LinearSearchTransposition(int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            if (i > 0)
            {
                Swap(&A[i], &A[i - 1]);
                return i - 1;
            }
            return i;
        }
    }
    return -1;
}

int Array::LinearSearchMoveToHead(int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            Swap(&A[i], &A[0]);
            return 0;
        }
    }
    return -1;
}

int Array::BinarySearchI(int low, int high, int key)
{
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (A[middle] == key)
            return middle;
        else if (key < A[middle])
            high = middle - 1;
        else if (key > A[middle])
            low = middle + 1;
    }
    return -1;
}

int Array::BinarySearchR(int low, int high, int key)
{
    int middle = (low + high) / 2;

    if (low > high)
    {
        if (A[middle] == key)
            return middle;
        else if (key < A[middle])
            return BinarySearchR(low, middle - 1, key);
        else if (key > A[middle])
            return BinarySearchR(middle + 1, high, key);
    }
    return -1;
}

int Array::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];

    cout << "Invalid index\n";
    return -1;
}

void Array::Set(int index, int value)
{
    if (index >= 0 && index < length)
    {
        A[index] = value;
        cout << "Set " << value << " at " << index << "\n";
    }
    else
        cout << "Invalid index\n";
}

int Array::Max()
{
    int max = INT_MIN, i;
    for (i = 0; i < length; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

int Array::Min()
{
    int min = INT_MAX, i;
    for (i = 0; i < length; i++)
        if (A[i] < min)
            min = A[i];
    return min;
}

int Array::SumI()
{
    int sum = 0, i;
    for (i = 0; i < length; i++)
        sum += A[i];
    return sum;
}

int Array::SumR(int n)
{
    if (n < 0)
        return 0;
    return SumR(n - 1) + A[n];
}

int Array::Avg()
{
    return SumI() / length;
}

Array::~Array()
{
    delete[] A;
    cout << "Bye-Bye\n";
}

void Menu(Array *a)
{
    int option, index, value;
    cout << "ARRAY ADT\n";
    cout << "1. Append\n";
    cout << "2. Insert\n";
    cout << "3. Delete\n";
    cout << "4. LinearSearch\n";
    cout << "5. LinearSearchTransposition\n";
    cout << "6. LinearSearchMoveToHead\n";
    cout << "7. BinarySearchI\n";
    cout << "8. BinarySearchR\n";
    cout << "9. Get\n";
    cout << "10. Set\n";
    cout << "11. Max\n";
    cout << "12. Min\n";
    cout << "13. Sum&Avg\n";
    cout << "0. Exit\n";
    cout << "Enter option: ";
    cin >> option;
    cout << "--------------------\n";
    switch (option)
    {
    case 1:
        cout << ENTER_VALUE;
        cin >> value;
        a->Append(value);
        break;
    case 2:
        cout << ENTER_INDEX_VALUE;
        cin >> index >> value;
        a->Insert(index, value);
        break;
    case 3:
        cout << ENTER_INDEX;
        cin >> index;
        a->Delete(index);
        break;
    case 4:
        cout << ENTER_VALUE;
        cin >> value;
        cout << "LinearSearch " << value << ":" << a->LinearSearch(value) << "\n";
        a->Display();
        break;
    case 5:
        cout << ENTER_VALUE;
        cin >> value;
        cout << "LinearSearchTransposition " << value << ":" << a->LinearSearchTransposition(value) << "\n";
        a->Display();
        break;
    case 6:
        cout << ENTER_VALUE;
        cin >> value;
        cout << "LinearSearchMoveToHead " << value << ":" << a->LinearSearchMoveToHead(value) << "\n";
        a->Display();
        break;
    case 7:
        cout << ENTER_VALUE;
        cin >> value;
        cout << "BinarySearchI " << value << ":" << a->BinarySearchI(0, a->length - 1, value) << "\n";
        a->Display();
        break;
    case 8:
        cout << ENTER_VALUE;
        cin >> value;
        cout << "BinarySearchR " << value << ":" << a->BinarySearchR(0, a->length - 1, value) << "\n";
        a->Display();
        break;
    case 9:
        cout << ENTER_INDEX;
        cin >> index;
        cout << "Value at " << index << " : " << a->Get(index) << "\n";
        a->Display();
        break;
    case 10:
        cout << ENTER_INDEX_VALUE;
        cin >> index >> value;
        a->Set(index, value);
        a->Display();
        break;
    case 11:
        cout << "Max: " << a->Max() << "\n";
        a->Display();
        break;
    case 12:
        cout << "Min: " << a->Min() << "\n";
        a->Display();
        break;
    case 13:
        cout << "SumR: " << a->SumR(a->length - 1) << "\n";
        cout << "SumI: " << a->SumI() << "\n";
        cout << "Avg: " << a->Avg() << "\n";
        a->Display();
        break;
    default:
        break;
    }
    cout << "--------------------\n";
    if (option != 0)
        Menu(a);
}

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    Array a(size);
    Menu(&a);
    return 0;
}
