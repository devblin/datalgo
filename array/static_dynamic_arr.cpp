#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[5];
    cout << A[0] << "\n";
    A[0] = 3;
    cout << A[0] << "\n";
    int *B;
    B = new int[5];
    cout << B[0] << "\n";
    B[0] = 3;
    cout << B[0] << "\n";
    cout << B << "\n";
    cout << *B << "\n";
    delete[] B;
}