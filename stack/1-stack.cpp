#include "stack.h"

void menu(Stack *s, StackLink *sl)
{
    int option, value, pos;
    cout << "----STACK----\n";
    cout << "1. pop\n2. push\n3. peek\n4. top\n5. display\n6. empty\n7. full\n";
    cout << "Option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        s->pop();
        sl->pop();
        break;
    case 2:
        cout << "Value: ";
        cin >> value;
        s->push(value);
        sl->push(value);
        break;
    case 3:
        cout << "Position: ";
        cin >> pos;
        cout << "Peek: " << s->peek(pos) << ", " << sl->peek(pos) << "\n";
        break;
    case 4:
        cout << "Top: " << s->top() << ", " << sl->top() << "\n";
        break;
    case 5:
        s->display();
        cout << "----\n";
        sl->display();
        break;
    case 6:
        cout << "Empty: " << s->empty() << ", " << sl->empty() << "\n";
        break;
    case 7:
        cout << "Full: " << s->full() << ", " << sl->full() << "\n";
        break;
    default:
        break;
    }
    if (option != 0)
        menu(s, sl);
}

int main()
{
    Stack *s = new Stack(5);
    StackLink *sl = new StackLink();
    menu(s, sl);
    return 0;
}