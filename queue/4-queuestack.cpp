#include "../stack/stack.h"

class QueueStack
{
private:
    StackLink *in, *out;

public:
    QueueStack();
    void enqueue(int value);
    void dequeue();
    void display();
};

QueueStack::QueueStack()
{
    in = new StackLink();
    out = new StackLink();
}

void QueueStack::enqueue(int value)
{
    if (!in->full())
        in->push(value);
    else
        cout << "Queue full\n";
}

void QueueStack::dequeue()
{
    if (!in->empty())
    {
        if (out->empty())
        {
            while (!in->empty())
            {
                out->push(in->top());
                in->pop();
            }
        }
        out->pop();
    }
    else if (!out->empty())
        out->pop();
    else
        cout << "Queue empty\n";
}

void QueueStack::display()
{
    cout << "IN: \n";
    if (!in->empty())
        in->display();
    cout << "OUT: \n";
    if (!out->empty())
        out->display();
}

void menu(QueueStack *qs)
{
    int option, value;
    cout << "---QUEUE USING STACK----\n";
    cout << "1.enqueue\n2.dequeue\n3.display\n0.exit\n";
    cout << "Enter option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "Enter value: ";
        cin >> value;
        qs->enqueue(value);
        break;
    case 2:
        qs->dequeue();
        break;
    case 3:
        qs->display();
        break;
    default:
        break;
    }
    if (option != 0)
        menu(qs);
}

int main()
{
    QueueStack *q = new QueueStack();
    menu(q);
    return 0;
}