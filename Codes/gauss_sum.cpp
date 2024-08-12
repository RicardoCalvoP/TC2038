/*
Ricardo Calvo - A01028889
Suma de Gauss

n ( n + 1 )
-----------
     2
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int gauss_sum()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    if (n < 1)
    {
        cout << "Err ";
        return -1;
    }
    else
    {
        return (n * (n + 1)) / 2;
    }
}

int main()
{
    system("cls");
    cout << gauss_sum();
    return 0;
}