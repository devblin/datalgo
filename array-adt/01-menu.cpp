#include <iostream>
#include <string>
using namespace std;

string INVALID_INDEX = "Array full or Invalid index",
       EMPTY_ARRAY = "Array empty",
       FULL_ARRAY = "Array full",
       ENTER_INDEX = "Enter index: ",
       ENTER_VALUE = "Enter value: ",
       ENTER_INDEX_VALUE = "Enter index & value: ";

template <class T>
void Swap(T *a, T *b)
{
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
class Array
{
public:
    T *A;
    int size;
    int length;

    Array(int newSize);
    void Display();
    void Append(T value);
    void Insert(int index, T value);
    void Delete(int index);
    int LinearSearch(T key);
    int LinearSearchTransposition(T key);
    int LinearSearchMoveToHead(T key);
    int BinarySearchI(int low, int high, T key);
    int BinarySearchR(int low, int high, T key);
    T Get(int index);
    void Set(int index, T value);
    T Max();
    T Min();
    T SumI();
    T SumR(int n);
    T Avg();
    void Reverse();
    void LeftShiftRotate();
    void RightShiftRotate();
    void InsertInSorted(T value);
    bool CheckSorted();
    void SeparateNegativePositive();
    ~Array();
};

template <class T>
Array<T>::Array(int newSize)
{
    size = newSize;
    A = new T[size];
    length = 0;
}

template <class T>
void Array<T>::Display()
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

template <class T>
void Array<T>::Append(T value)
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

template <class T>
void Array<T>::Insert(int index, T value)
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
        cout << INVALID_INDEX << "\n";

    Display();
    cout << "\n";
}

template <class T>
void Array<T>::Delete(int index)
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

template <class T>
int Array<T>::LinearSearch(T key)
{
    int i;
    for (i = 0; i < length; i++)
        if (A[i] == key)
            return i;
    return -1;
}

template <class T>
int Array<T>::LinearSearchTransposition(T key)
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

template <class T>
int Array<T>::LinearSearchMoveToHead(T key)
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

template <class T>
int Array<T>::BinarySearchI(int low, int high, T key)
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

template <class T>
int Array<T>::BinarySearchR(int low, int high, T key)
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

template <class T>
T Array<T>::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];

    cout << "Invalid index\n";
    return -1;
}

template <class T>
void Array<T>::Set(int index, T value)
{
    if (index >= 0 && index < length)
    {
        A[index] = value;
        cout << "Set " << value << " at " << index << "\n";
    }
    else
        cout << "Invalid index\n";
}

template <class T>
T Array<T>::Max()
{
    int max = INT_MIN, i;
    for (i = 0; i < length; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

template <class T>
T Array<T>::Min()
{
    int min = INT_MAX, i;
    for (i = 0; i < length; i++)
        if (A[i] < min)
            min = A[i];
    return min;
}

template <class T>
T Array<T>::SumI()
{
    T sum = 0;
    int i;
    for (i = 0; i < length; i++)
        sum += A[i];
    return sum;
}

template <class T>
T Array<T>::SumR(int n)
{
    if (n < 0)
        return 0;
    return SumR(n - 1) + A[n];
}

template <class T>
T Array<T>::Avg()
{
    return SumI() / length;
}

template <class T>
void Array<T>::Reverse()
{
    int i;
    cout << "Reverse using copying array: ";
    int B[length];
    for (i = 0; i < length; i++)
        B[length - i - 1] = A[i];
    for (i = 0; i < length; i++)
        A[i] = B[i];
    Display();
    cout << "Reverse by swaping elements: ";
    for (i = 0; i < length / 2; i++)
        Swap(&A[i], &A[length - i - 1]);
    Display();
}

template <class T>
void Array<T>::LeftShiftRotate()
{
    int i;
    T first;
    cout << "LeftShift: ";
    first = A[0];
    for (i = 0; i < length - 1; i++)
        A[i] = A[i + 1];
    A[i] = 0;
    Display();
    cout << "LeftRotate: ";
    A[i] = first;
    Display();
}

template <class T>
void Array<T>::RightShiftRotate()
{
    int i;
    T last;
    cout << "RightShift: ";
    last = A[length - 1];
    for (i = length - 1; i > 0; i--)
        A[i] = A[i - 1];
    A[i] = 0;
    Display();
    cout << "RightRotate: ";
    A[i] = last;
    Display();
}

template <class T>
void Array<T>::InsertInSorted(T value)
{
    int i;
    for (i = length - 1; i >= 0; i--)
        if (value > A[i])
            break;
    Insert(i + 1, value);
}

template <class T>
bool Array<T>::CheckSorted()
{
    int i;
    for (i = 0; i < length - 1; i++)
        if (A[i] > A[i + 1])
            return false;
    return true;
}

template <class T>
void Array<T>::SeparateNegativePositive()
{
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] > 0)
            j--;
        if (i < j)
            Swap(&A[i], &A[j]);
    }
    Display();
}

template <class T>
Array<T>::~Array()
{
    delete[] A;
    cout << "Bye-Bye\n";
}

template <class T>
void Menu(Array<T> *a)
{
    int option, index;
    T value;
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
    cout << "14. Reverse\n";
    cout << "15. LeftShiftRotate\n";
    cout << "16. RightShiftRotate\n";
    cout << "17. InsertInSorted\n";
    cout << "18. CheckSorted\n";
    cout << "19. SeparateNegativePositive\n";
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
    case 14:
        a->Reverse();
        a->Display();
        break;
    case 15:
        a->LeftShiftRotate();
        break;
    case 16:
        a->RightShiftRotate();
        break;
    case 17:
        cout << ENTER_VALUE;
        cin >> value;
        a->InsertInSorted(value);
        break;
    case 18:
        cout << "Is array sorted? " << a->CheckSorted() << "\n";
        break;
    case 19:
        a->SeparateNegativePositive();
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
    Array<float> a(size);
    Menu(&a);
    return 0;
}
