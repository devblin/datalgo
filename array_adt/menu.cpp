#include <bits/stdc++.h>
using namespace std;

string INVALID_INDEX = "Array full or Invalid index",
       EMPTY_ARRAY = "Array empty",
       FULL_ARRAY = "Array full",
       ENTER_INDEX = "Enter index: ",
       ENTER_VALUE = "Enter value: ",
       ENTER_INDEX_VALUE = "Enter index & value: ";

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array(int newSize);
    void Display();
    void Append(int value);
    void Insert(int index, int value);
    void Delete(int index);
    int Search(int value);
    int Get(int index);
    void Set(int index, int value);
    int Max();
    int Min();
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
        Display();
    }
    else
        cout << FULL_ARRAY;
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
        Display();
    }
    else
        cout << INVALID_INDEX;
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
    cout << "\n";
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
    cout << "0. Exit\n";
    cout << "Enter option: ";
    cin >> option;
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
    default:
        break;
    }
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
