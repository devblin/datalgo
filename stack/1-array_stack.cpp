#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *A;
    int size;
    int topPt = -1;

public:
    Stack(int stackSize);
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    int peek(int pos);
    int top();
    void display();
};

Stack::Stack(int stackSize)
{
    stackSize = size;
    A = new int[size];
}

void menu(Stack *s)
{
    int option, value, pos;
    cout << "----ARRAY STACK----";
    cout << "1. pop\n2. push\n3. peek\n4. top\n5. display\n6. isempty\n7. isfull\n";
    cout << "Option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "Popped: " << s->pop() << "\n";
        break;
    case 2:
        cout << "Value: ";
        cin >> value;
        s->push(value);
        break;
    case 3:
        cout << "Position: ";
        cin >> pos;
        cout << "Peek: " << s->peek(pos) << "\n";
        break;
    case 4:
        cout << "Top: " << s->top() << "\n";
        break;
    case 5:
        s->display();
        break;
    case 6:
        cout << "isEmpty: " << s->isEmpty() << "\n";
        break;
    case 7:
        cout << "isFUll: " << s->isFull() << "\n";
        break;
    default:
        break;
    }
    if (option != 0)
        menu(s);
}

int main()
{
    Stack *s;
}