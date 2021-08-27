#ifndef DISPLAY
#define DISPLAY

#include <iostream>
using namespace std;

void display(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

#endif